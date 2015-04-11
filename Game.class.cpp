// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:49:45 by gchateau          #+#    #+#             //
//   Updated: 2015/04/11 17:46:15 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include "Menu.class.hpp"
#include <unistd.h>
#include <ctime>
#include <string>
#include <iostream>

// CONSTRUCTORS AND DESTRUCTOR

Game::Game(void)
{}

Game::Game(Game const & src)
{
	if (this != &src)
		*this = src;
}

Game::~Game(void)
{}

// OPERATORS OVERLOAD

Game &		Game::operator=(Game const & rhs)
{
	if (this != &rhs)
	{
		this->_player = rhs.getPlayer();
		this->_entities = rhs.getEntities();
	}
	return (*this);
}

// ENGINE

void			Game::init(Screen *screen)
{
	this->_player.setPosition(screen->getWidth() / 2, screen->getHeight() - 1);
	clear();
}

void			Game::handle(Screen *screen)
{
	int			ch = wgetch(screen->getWindow());

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

void			Game::update(Screen *screen)
{
	std::string	msg = "Game state";

	mvprintw(screen->getHeight() / 2, (screen->getWidth() - msg.length()) / 2, msg.c_str());
}

void			Game::draw(Screen *screen)
{	
//	Entity			*list;

	werase(screen->getWindow());
	// list = this->_entities.getEntities();
	// while (list != NULL)
	// {
	// 	mvwprintw(screen->getWindow(), list->getX(), list->getY(), list->getBodyS().c_str());
	// 	list = list->getNext();
	// }
	mvwprintw(screen->getWindow(), this->_player.getY(), this->_player.getX(), this->_player.getBodyS().c_str());
	wrefresh(screen->getWindow());
	this->_cEnd = std::clock();
	// if ((this->_cEnd - this->_cStart) / CLOCKS_PER_SEC < (1000 / GAME_FPS))
	// 	usleep((1000 / GAME_FPS) - ((this->_cEnd - this->_cStart) / CLOCKS_PER_SEC));
}

// GETTERS

Player const &		Game::getPlayer(void) const
{
	return (this->_player);
}

Entities const &		Game::getEntities(void) const
{
	return (this->_entities);
}
