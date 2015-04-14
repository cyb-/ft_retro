/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:52:16 by jzimini           #+#    #+#             */
//   Updated: 2015/04/14 10:46:40 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Player.hpp"
#include "Rifle.hpp"

Player::Player(void) : AEntity(0, 0, "player", 94, 2, 3, 0, -1, 1)
{}

Player::Player(Player const & src) : AEntity(src.getX(), src.getY(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector(), src.getSpeed())
{
	*this = src;
}

Player::~Player()
{}

Player &			Player::operator=(Player const & rhs)
{
	if (this != &rhs)
	{
		_PosY = rhs.getY();
		_PosX = rhs.getX();
		_Type = rhs.getType();
		_Body = rhs.getBody();
		_HP = rhs.getHP();
		_Lives = rhs.getLives();
	}
	return (*this);
}

Player &			Player::operator+=(int score)
{
	this->_score += score;
	return (*this);
}

Player &			Player::operator-=(int hp)
{
	this->_HP -= hp;
	return (*this);
}

AEntity *			Player::clone(void) const
{
	AEntity *	entity = new Player(*this);
	return (entity);
}

int					Player::getScore(void) const
{
	return (this->_score);
}

// ************************************************************************** //
//                                  ACTIONS                                   //
// ************************************************************************** //

AEntity *			Player::shoot(void)
{
	return (new Rifle(this->_PosX, this->_PosY + this->_vector, this->_vector));
}

void				Player::respawn(int x, int y)
{
	if (_Lives > 0)
		_HP = 2;
	this->setBody(94);
	this->setPosition(x, y);
}

void				Player::attack(Screen *screen, Game *game)
{
	(void)screen;
	game->addEntity(this->shoot());
}

void				Player::escape(Screen *screen, Game *game)
{
	(void)game;
	screen->setState(Screen::MENU);
}

// ************************************************************************** //
//                                 MOVEMENTS                                  //
// ************************************************************************** //

void			Player::moveUp(Screen *screen, Game *game)
{
	(void)screen;
	(void)game;
	if (this->getY() > 0)
		this->_PosY--;
}

void			Player::moveDown(Screen *screen, Game *game)
{
	(void)game;
	if (this->getY() < screen->getMaxY())
		this->_PosY++;
}

void			Player::moveLeft(Screen *screen, Game *game)
{
	(void)screen;
	(void)game;
	if (this->getX() > 0)
		this->_PosX--;
}

void			Player::moveRight(Screen *screen, Game *game)
{
	(void)game;
	if (this->getX() < screen->getMaxX())
		this->_PosX++;
}

// ************************************************************************** //
//                              Player::KeyHook                               //
// ************************************************************************** //

Player::KeyHook::KeyHook(void) : _key(0), _callback(0)
{}

Player::KeyHook::KeyHook(int key, Player::fKey_t callback) : _key(key), _callback(callback)
{}

Player::KeyHook::KeyHook(Player::KeyHook const & src) : _key(src.key()), _callback(src.callback())
{}

Player::KeyHook::~KeyHook(void)
{}

Player::KeyHook &	Player::KeyHook::operator=(Player::KeyHook const & rhs)
{
	if (this != &rhs)
	{
		this->_key = rhs.key();
		this->_callback = rhs.callback();
	}
	return (*this);
}

bool				Player::KeyHook::operator==(int key)
{
	return (this->_key == key);
}

int					Player::KeyHook::key(void) const
{
	return (this->_key);
}

Player::fKey_t		Player::KeyHook::callback(void) const
{
	return (this->_callback);
}
