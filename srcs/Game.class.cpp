// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:49:45 by gchateau          #+#    #+#             //
//   Updated: 2015/04/14 10:51:00 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include "Enemy.hpp"
#include "Rock.hpp"

#include <cstdlib>
#include <sstream>

int		Game::_wavesPerSec = 1;
int		Game::_wavesDelay = 5;
int		Game::_UIHeight = 4;

Game::Game(void) : _score(0), _last_wave(0), _game_start(std::clock())
{}

Game::Game(Game const & src) : _last_wave(0), _game_start(std::clock())
{
	*this = src;
}

Game::~Game(void)
{}

Game &				Game::operator=(Game const & rhs)
{
	if (this != &rhs)
	{
		this->_score = rhs.getScore();
		this->_player = rhs.getPlayer();
		this->_entities = rhs.getEntities();
	}
	return (*this);
}

// ************************************************************************** //
//                                   ENGINE                                   //
// ************************************************************************** //

void				Game::init(Screen *screen)
{
	this->_player.setPosition(screen->getWidth() / 2, screen->getMaxY());
	this->_generateWave(screen);
}

void				Game::handle(Screen *screen)
{
	int					hKey = wgetch(screen->getWindow());
	unsigned int		i = 0;
	Player::KeyHook		moveKeys[] = {
		Player::KeyHook(KEY_ESC, &Player::escape),
		Player::KeyHook(KEY_UP, &Player::moveUp),
		Player::KeyHook(KEY_DOWN, &Player::moveDown),
		Player::KeyHook(KEY_LEFT, &Player::moveLeft),
		Player::KeyHook(KEY_RIGHT, &Player::moveRight),
		Player::KeyHook(KEY_SPACE, &Player::attack)
	};

	while (i < (sizeof(moveKeys) / sizeof(moveKeys[0])))
	{
		if (moveKeys[i] == hKey)
		{
			(this->_player.*moveKeys[i].callback())(screen, this);
			break ;
		}
		i++;
	}
}

void				Game::update(Screen *screen)
{
	Entities::Item *	lst;
	Entities::Item *	del;

	this->_generateWave(screen);
	lst = this->_entities.getItems();
	while (lst)
	{
		if (lst->hasEntity())
		{
			lst->getEntity()->move();
			this->_entities.push(lst->getEntity()->shoot());
			this->_checkCollision(lst->getEntity());
		}
		if (lst->hasEntity()
			&& lst->getEntity()->getY() >= 0
			&& lst->getEntity()->getY() < screen->getHeight() - Game::_UIHeight
			&& (lst->getEntity()->getLives() > 0
				|| (lst->getEntity()->getLives() <= 0 && !lst->getEntity()->canMove())))
			lst = lst->getNext();
		else
		{
			del = lst;
			lst = lst->getNext();
			this->_entities.remove(del->getIndex());
		}
	}
	this->_checkPlayer(screen);
}

void				Game::render(Screen *screen)
{
	Entities::Item *	lst;

	screen->erase();
	lst = this->_entities.getItems();
	while (lst)
	{
		screen->put(lst->getEntity()->getX(), lst->getEntity()->getY(), lst->getEntity()->getBody());
		lst = lst->getNext();
	}
	screen->put(this->_player.getX(), this->_player.getY(), this->_player.getBody());
	this->_displayUI(screen);
	screen->refresh();
}

// ************************************************************************** //
//                                  GETTERS                                   //
// ************************************************************************** //

unsigned int		Game::getScore(void) const
{
	return (this->_score);
}

Player const &		Game::getPlayer(void) const
{
	return (this->_player);
}

Entities const &	Game::getEntities(void) const
{
	return (this->_entities);
}

// ************************************************************************** //
//                                GAME HELPERS                                //
// ************************************************************************** //

void				Game::addEntity(AEntity *entity)
{
	this->_entities.push(entity);
}

void				Game::delEntity(int index)
{
	this->_entities.remove(index);
}

void				Game::_checkCollision(AEntity *entity)
{
	Entities::Item *	tmp;

	tmp = this->_entities.getItems();
	while (tmp)
	{
		if (entity->collision(tmp->getEntity()))
				this->_player += (entity->getVector() < 0 ? tmp->getEntity()->getPoints() : 0);
		tmp = tmp->getNext();
	}
}

void				Game::_checkPlayer(Screen *screen)
{
	this->_checkCollision((AEntity*)&this->_player);
	if (this->_player.getHP() <= 0)
		this->_player.respawn(screen->getWidth() / 2, screen->getMaxY());
	if (this->_player.getLives() <= 0)
		screen->setState(Screen::GAMEOVER);
	if (this->_player.getX() > screen->getMaxX())
		this->_player.setPosition(screen->getMaxX(), this->_player.getY());
	if (this->_player.getY() > screen->getMaxY() - Game::_UIHeight)
		this->_player.setPosition(this->_player.getX(), screen->getMaxY() - Game::_UIHeight);
}

// ************************************************************************** //
//                                WAVE HELPERS                                //
// ************************************************************************** //

bool				Game::_canGenerateWave(void)
{
	clock_t				current = std::clock();

	if (this->_last_wave != 0
		&& (current - this->_last_wave) < (clock_t)((CLOCKS_PER_SEC * Game::_wavesDelay) / Game::_wavesPerSec))
		return (false);
	this->_last_wave = current;
	return (true);
}

void				Game::_generateWave(Screen *screen)
{
	int					nb = (std::rand() % 8) + 1;
	int					colW;
	AEntity *			entity;
	AEntity *			rock;

	if (!this->_canGenerateWave())
		return ;
	colW = screen->getWidth() / nb;
	while (nb)
	{
		int	x = (std::rand() % colW) + ((nb - 1) * colW);
		entity = new Enemy(x, 0);
		if (entity)
			this->_entities.push(entity);
		if (x % colW == 0)
		{
			for (int i = 0; i < 3 && x + i < screen->getMaxX(); i++)
			{
				rock = new Rock(x + i , 0);
				if (rock)
					this->_entities.push(rock);
			}
		}
		nb--;
	}
}

// ************************************************************************** //
//                                 UI HELPERS                                 //
// ************************************************************************** //

void				Game::_displayUI(Screen *screen) const
{
	int					y = screen->getHeight() - Game::_UIHeight;
	std::stringstream	hp;
	std::stringstream	lives;
	std::stringstream	score;
	std::stringstream	duration;

	screen->separator(y);
	hp << "HP: " << this->_player.getHP();
	lives << "Lives: " << this->_player.getLives();
	score << "Score: " << this->_player.getScore();
	duration << "Started: " << ((std::clock() - this->_game_start) / CLOCKS_PER_SEC) << "secs ago";
	screen->put(1, y + 1, hp.str());
	screen->put(1, y + 2, lives.str());
	screen->put(screen->getMaxX() - score.str().length(), y + 1, score.str());
	screen->put(screen->getMaxX() - duration.str().length(), y + 3, duration.str());
}
