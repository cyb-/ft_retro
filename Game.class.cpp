// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:49:45 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 01:15:49 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include "Menu.class.hpp"
#include "Enemy.hpp"

#include <unistd.h> // For usleep()
#include <ctime>
#include <cstdlib>
#include <iostream>

Game::Game(void) : _loops(0)
{}

Game::Game(Game const & src)
{
	if (this != &src)
		*this = src;
}

Game::~Game(void)
{}

// ************************************************************************** //
//                             OPERATORS OVERLOAD                             //
// ************************************************************************** //

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
	this->_player.setPosition(screen->getWidth() / 2, screen->getHeight() - 1);
	wclear(screen->getWindow());
}

void				Game::handle(Screen *screen)
{
	int					ch = wgetch(screen->getWindow());

	this->_cStart = std::clock();
	switch (ch)
	{
	case KEY_ESC:
		screen->changeState(new Menu());
		break;
	case KEY_LEFT:
		if (this->_player.getX() > 0)
			this->_player.move("left");
		break;
	case KEY_RIGHT:
		if (this->_player.getX() < screen->getWidth() - 1)
			this->_player.move("right");
		break;
	case KEY_UP:
		if (this->_player.getY() > 0)
			this->_player.move("up");
		break;
	case KEY_DOWN:
		if (this->_player.getY() < screen->getHeight() - 1)
			this->_player.move("down");
		break;
	case KEY_SPACE:
		this->_player.shoot();
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
		if (lst->hasEntity() && lst->getEntity()->getHP() > 0)
		{
			lst->getEntity()->move("down");
			lst = lst->getNext();
		}
		else
		{
			del = lst;
			lst = lst->getNext();
			delete del;
		}
	}
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
	wrefresh(screen->getWindow());
	this->_cEnd = std::clock();
	this->_loops++;
	if ((this->_cEnd - this->_cStart) / CLOCKS_PER_SEC < (CLOCKS_PER_SEC / GAME_FPS))
		usleep((CLOCKS_PER_SEC / GAME_FPS) - ((this->_cEnd - this->_cStart) / CLOCKS_PER_SEC));
}

// ************************************************************************** //
//                                  GETTERS                                   //
// ************************************************************************** //

unsigned int		Game::getLoops(void) const
{
	return (this->_loops);
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
