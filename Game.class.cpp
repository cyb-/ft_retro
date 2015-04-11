// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:49:45 by gchateau          #+#    #+#             //
//   Updated: 2015/04/11 19:49:31 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include "Menu.class.hpp"
#include "Enemy.hpp"
#include <unistd.h>
#include <ctime>
#include <string>
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
	clear();
}

void				Game::handle(Screen *screen)
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

void				Game::update(Screen *screen)
{
	Entity *			lst;

	if ((this->_loops % 11) != 0) // THIS IS A FUNCKIN TRICK !!!!!!
		return ;
	if ((this->_loops % 5) == 0)
		this->_generateWave(screen);
	lst = this->_entities.getEntities();
	while (lst)
	{
		lst->move("down");
		lst = lst->getNext();
	}
}

void				Game::draw(Screen *screen)
{	
	Entity			*list;

	werase(screen->getWindow());
	list = this->_entities.getEntities();
	while (list != NULL)
	{
		mvwprintw(screen->getWindow(), list->getY(), list->getX(), list->getBodyS().c_str());
		list = list->getNext();
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
	int	i = 5;

	while (i--)
	{
		Entity *	entity = new Enemy(screen->getWidth() - (i * 3), 0);
		if (entity)
			this->_entities.push(entity);
	}
}
