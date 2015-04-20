// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/18 02:24:57 by gchateau          #+#    #+#             //
//   Updated: 2015/04/21 01:12:09 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include "Player.class.hpp"
#include "Rifle.hpp"

Player::Player(void) : AEntity(0, 0, -1, 1, 100, 100, 50, 2, 0, true)
{}

Player::Player(Player const & src) : AEntity(src.getX(), src.getY(), src.getVector(), src.getSpeed(), src.getCHP(), src.getMHP(), src.getDamages(), src.getLives(), src.getPoints(), src.getCollidable())
{}

Player::~Player()
{}

Player &			Player::operator=(Player const & rhs)
{
	if (this != &rhs)
	{
		this->_posY = rhs.getY();
		this->_posX = rhs.getX();
		this->_vector = rhs.getVector();
		this->_speed = rhs.getSpeed();
		this->_cHP = rhs.getCHP();
		this->_mHP = rhs.getMHP();
		this->_damages = rhs.getDamages();
		this->_lives = rhs.getLives();
		this->_points = rhs.getPoints();
		this->_collidable = rhs.getCollidable();
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
	this->takeDamages(hp);
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

int					Player::getBody(void) const
{
	return ('^');
}

// ************************************************************************** //
//                                  ACTIONS                                   //
// ************************************************************************** //

AEntity *			Player::shoot(void)
{
	return (new Rifle(this->_posX, this->_posY + this->_vector, this->_vector));
}

void				Player::respawn(int x, int y)
{
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
		this->_posY--;
}

void			Player::moveDown(Screen *screen, Game *game)
{
	(void)game;
	if (this->getY() < screen->getMaxY())
		this->_posY++;
}

void			Player::moveLeft(Screen *screen, Game *game)
{
	(void)screen;
	(void)game;
	if (this->getX() > 0)
		this->_posX--;
}

void			Player::moveRight(Screen *screen, Game *game)
{
	(void)game;
	if (this->getX() < screen->getMaxX())
		this->_posX++;
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
