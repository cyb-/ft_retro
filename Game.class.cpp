// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:49:45 by gchateau          #+#    #+#             //
//   Updated: 2015/04/11 13:43:07 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include "Menu.class.hpp"
#include <unistd.h>
#include <ctime>
#include <string>

// CONSTRUCTORS AND DESTRUCTOR

Game::Game(void) : _entities()
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
	this->_player.setPosition(screen->getWidth() / 2, screen->getHeight());
	clear();
}

void			Game::handle(Screen *screen)
{
	int			ch = wgetch(screen->getWindow());

	this->_cStart = std::clock();
	if (ch == KEY_ESC)
		screen->changeState(new Menu());
}

void			Game::update(Screen *screen)
{
	std::string	msg = "Game state";

	mvprintw(screen->getHeight() / 2, (screen->getWidth() - msg.length()) / 2, msg.c_str());
}

void			Game::draw(Screen *screen)
{	
//	Entity			*list;

	// list = this->_entities.getEntities();
	// while (list != NULL)
	// {
	// 	mvwprintw(screen->getWindow(), list->getX(), list->getY(), list->getBodyS().c_str());
	// 	list = list->getNext();
	// }
	this->_player.setPosition(screen->getWidth() / 2, screen->getHeight() - 10);
	mvwprintw(screen->getWindow(), this->_player.getX(), this->_player.getY(), this->_player.getBodyS().c_str());
	refresh();
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
