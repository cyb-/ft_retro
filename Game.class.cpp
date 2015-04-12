// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:49:45 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 11:48:52 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include "Enemy.hpp"

#include <cstdlib>
#include <sstream>

int		Game::_UIHeight = 3;

Game::Game(void) : _loops(0), _score(0)
{}

Game::Game(Game const & src)
{
	*this = src;
}

Game::~Game(void)
{}

Game &				Game::operator=(Game const & rhs)
{
	if (this != &rhs)
	{
		this->_loops = rhs.getLoops();
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
}

void				Game::handle(Screen *screen)
{
	int					ch = wgetch(screen->getWindow());

	switch (ch)
	{
	case KEY_ESC:
		screen->setState(Screen::MENU);
		break;
	case KEY_LEFT:
		if (this->_player.getX() > 0)
			this->_player.move("left");
		break;
	case KEY_RIGHT:
		if (this->_player.getX() < screen->getMaxX())
			this->_player.move("right");
		break;
	case KEY_UP:
		if (this->_player.getY() > 0)
			this->_player.move("up");
		break;
	case KEY_DOWN:
		if (this->_player.getY() < screen->getMaxY() - Game::_UIHeight)
			this->_player.move("down");
		break;
	case KEY_SPACE:
		this->_entities.push(this->_player.shoot());
	}
}

void				Game::update(Screen *screen)
{
	Entities::Item *	lst;
	Entities::Item *	del;

	if ((this->_loops % 11) != 0) // THIS IS A FUCKIN TRICK !!!!!!
		return ;
	if ((this->_loops % 5) == 0 || this->_loops == 0)
		this->_generateWave(screen);
	lst = this->_entities.getItems();
	while (lst)
	{
		if (lst->hasEntity())
		{
			lst->getEntity()->move();
			this->_checkCollision(lst->getEntity());
		}
		if (lst->hasEntity()
			&& lst->getEntity()->getLives() > 0
			&& lst->getEntity()->getY() < screen->getHeight() - Game::_UIHeight)
			lst = lst->getNext();
		else
		{
			del = lst;
			lst = lst->getNext();
			this->_entities.remove(del->getIndex());
		}
	}
	this->_checkCollision((Entity*)&this->_player);
	if (this->_player.getHP() <= 0)
		this->_player.respawn(screen->getWidth() / 2, screen->getMaxY());
	if (this->_player.getLives() <= 0)
		mvwprintw(screen->getWindow(), screen->getHeight() - (Game::_UIHeight + 1), 1, "Dead");
	if (this->_player.getX() > screen->getMaxX())
		this->_player.setPosition(screen->getMaxX(), this->_player.getY());
	if (this->_player.getY() > screen->getMaxY() - Game::_UIHeight)
		this->_player.setPosition(this->_player.getX(), screen->getMaxY() - Game::_UIHeight);
}

void				Game::render(Screen *screen)
{
	Entities::Item *	lst;

	werase(screen->getWindow());
	lst = this->_entities.getItems();
	while (lst)
	{
		mvwaddch(screen->getWindow(), lst->getEntity()->getY(), lst->getEntity()->getX(), lst->getEntity()->getBody());
		lst = lst->getNext();
	}
	mvwaddch(screen->getWindow(), this->_player.getY(), this->_player.getX(), this->_player.getBody());
	this->_displayUI(screen);
	wrefresh(screen->getWindow());
	this->_loops++;
}

// ************************************************************************** //
//                                  GETTERS                                   //
// ************************************************************************** //

unsigned int		Game::getLoops(void) const
{
	return (this->_loops);
}

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

void				Game::_displayUI(Screen *screen) const
{
	int					x, y;
	std::stringstream	hp;
	std::stringstream	lives;
	std::stringstream	score;

	y = screen->getHeight() - Game::_UIHeight;
	for (x = 0; x < screen->getWidth(); x++)
		mvwaddch(screen->getWindow(), y, x, ' ' | A_REVERSE);
	hp << "HP: " << this->_player.getHP();
	lives << "Lives: " << this->_player.getLives();
	score << "Score: " << this->_score;
	mvwprintw(screen->getWindow(), y + 1, 1, hp.str().c_str());
	mvwprintw(screen->getWindow(), y + 2, 1, lives.str().c_str());
	mvwprintw(screen->getWindow(), y + 1, screen->getMaxX() - score.str().length(), score.str().c_str());
}

void				Game::_generateWave(Screen *screen)
{
	int					nb = (std::rand() % 8) + 1;
	int					colW;
	Entity *			entity;

	colW = screen->getWidth() / nb;
	while (nb)
	{
		int	x = (std::rand() % colW) + ((nb - 1) * colW);
		entity = new Enemy(x, 0);
		if (entity)
			this->_entities.push(entity);
		nb--;
	}
}

void				Game::_checkCollision(Entity *entity)
{
	Entities::Item *	tmp;

	tmp = this->_entities.getItems();
	while (tmp)
	{
		if (entity->collision(tmp->getEntity()))
		{
			if ((entity->getVector() > 0 && tmp->getEntity()->getVector() < 0)
				|| (entity->getVector() < 0 && tmp->getEntity()->getVector() > 0))
				this->_score += (entity->getVector() < 0 ? tmp->getEntity()->getPoints() : 0);
		}
		tmp = tmp->getNext();
	}
}
