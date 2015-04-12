// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:49:45 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 05:39:01 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include "Enemy.hpp"

#include <cstdlib>

int		Game::_UIHeight = 3;

Game::Game(void) : _loops(0)
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
// ADD: `&& lst->getEntity()->getY() < screen->getMaxY() - Game::_UIHeight` condition to remove outscreen entities
		if (lst->hasEntity() && lst->getEntity()->getHP() > 0)
		{
			if (lst->getEntity()->getVector() == 1)
				lst->getEntity()->move("down");
			if (lst->getEntity()->getVector() == -1)
				lst->getEntity()->move("up");
			lst = lst->getNext();
		}
		else
		{
			del = lst;
			lst = lst->getNext();
			delete del;
		}
	}
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
		mvwprintw(screen->getWindow(), lst->getEntity()->getY(), lst->getEntity()->getX(), lst->getEntity()->getBodyS().c_str());
		lst = lst->getNext();
	}
	mvwprintw(screen->getWindow(), this->_player.getY(), this->_player.getX(), this->_player.getBodyS().c_str());
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

	y = screen->getHeight() - Game::_UIHeight;
	for (x = 0; x < screen->getWidth(); x++)
		mvwaddch(screen->getWindow(), y, x, ' ' | A_REVERSE);
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
