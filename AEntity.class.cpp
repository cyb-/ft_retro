// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEntity.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/12 16:43:05 by gchateau          #+#    #+#             //
//   Updated: 2015/04/13 22:14:21 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AEntity.class.hpp"

AEntity::AEntity(int x, int y, std::string type, char body, int hp, int lives, int points, int Vector, int speed) : _PosY(y),
																												  _PosX(x),
																												  _Body(body),
																												  _HP(hp),
																												  _Lives(lives),
																												  _Collidable(true),
																												  _Type(type),
																												  _Points(points),
																												  _vector(Vector),
																												  _speed(speed),
																												  _last_move(std::clock()),
																												  _last_shoot(std::clock())
{}

AEntity::AEntity(AEntity const & src) : _last_move(std::clock()), _last_shoot(std::clock())
{
	*this = src;
}

AEntity::~AEntity()
{}

AEntity &		AEntity::operator=(AEntity const & rhs)
{
	if (this != &rhs)
	{
		this->_PosY = rhs.getY();
		this->_PosX = rhs.getX();
		this->_Type = rhs.getType();
		this->_Body = rhs.getBody();
		this->_speed = rhs.getSpeed();
	}
	return (*this);
}

// ************************************************************************** //
//                                  GETTERS                                   //
// ************************************************************************** //

int				AEntity::getY(void) const
{
	return (_PosY);
}

int				AEntity::getX(void) const
{
	return (_PosX);
}

int				AEntity::getLives(void) const
{
	return (_Lives);
}

int				AEntity::getHP(void) const
{
	return (_HP);
}

std::string		AEntity::getType(void) const
{
	return (_Type);
}

bool			AEntity::getCollidable(void) const
{
	return (_Collidable);
}

char			AEntity::getBody(void) const
{
	return (_Body);
}

int				AEntity::getPoints(void) const
{
	return (_Points);
}

int				AEntity::getVector(void) const
{
	return (this->_vector);
}

int				AEntity::getSpeed(void) const
{
	return (this->_speed);
}

// ************************************************************************** //
//                                  MUTATORS                                  //
// ************************************************************************** //

void			AEntity::setBody(char body)
{
	_Body = body;
}

void			AEntity::setHP(int i)
{
	_HP = i;
	if (_HP <= 0)
		this->looseLife();
}

void			AEntity::setPosition(int x, int y)
{
	this->_PosX = x;
	this->_PosY = y;
}

// ************************************************************************** //
//                                 MOVEMENTS                                  //
// ************************************************************************** //

bool			AEntity::canMove(void)
{
	clock_t			current = std::clock();

	if ((current - this->_last_move) < (clock_t)(CLOCKS_PER_SEC / this->_speed))
		return (false);
	this->_last_move = current;
	return (true);
}

void			AEntity::moveUp(Screen *screen)
{
	(void)screen;
	if (this->getY() > 0)
		this->_PosY--;
}

void			AEntity::moveDown(Screen *screen)
{
	if (this->getY() < screen->getMaxY())
		this->_PosY++;
}

void			AEntity::moveLeft(Screen *screen)
{
	(void)screen;
	if (this->getX() > 0)
		this->_PosX--;
}

void			AEntity::moveRight(Screen *screen)
{
	if (this->getX() < screen->getMaxX())
		this->_PosX++;
}

void			AEntity::move(void)
{
	if (this->canMove())
		this->_PosY += (this->_vector < 0 ? -1 : 1);
}

void			AEntity::move(std::string direction)
{
	if (direction.compare("up") == 0)
		_PosY--;
	else if (direction.compare("down") == 0)
		_PosY++;
	else if (direction.compare("right") == 0)
		_PosX++;
	else if (direction.compare("left") == 0)
		_PosX--;
}

// ************************************************************************** //
//                                  HELPERS                                   //
// ************************************************************************** //

void			AEntity::looseHP(void)
{
	_HP -= 1;
	if (_Body == 'W' && _HP > 0)
		this->setBody('V');
	else if (_HP <= 0)
		this->looseLife();
}

void			AEntity::looseLife(void)
{
	_Lives -= 1;
	this->setBody('*');
}

bool			AEntity::collision(AEntity *entity)
{
	if (this != entity && this->_PosX == entity->getX() && this->_PosY == entity->getY())
	{
		if (entity->getVector() != this->getVector() && this->_Collidable && entity->getCollidable())
		{
			if (!entity->getType().compare("enemy"))
			{
				this->setHP(0);
				entity->looseHP();
			}
			else
			{
				entity->looseHP();
				this->looseHP();
			}
			return (true);
		}
		else if (!entity->getCollidable() != !this->getCollidable())
		{
			if (!this->_Collidable && entity->getType() == "rifle")
				entity->looseHP();
			else if (!entity->getCollidable() && !this->_Type.compare("rifle"))
				this->looseHP();
			return (true);
		}
	}

	return (false);
}

// ************************************************************************** //
//                              AEntity::KeyHook                              //
// ************************************************************************** //

AEntity::KeyHook::KeyHook(void) : _key(0), _callback(0)
{}

AEntity::KeyHook::KeyHook(int key, AEntity::fKey_t callback) : _key(key), _callback(callback)
{}

AEntity::KeyHook::KeyHook(AEntity::KeyHook const & src) : _key(src.key()), _callback(src.callback())
{}

AEntity::KeyHook::~KeyHook(void)
{}

AEntity::KeyHook &	AEntity::KeyHook::operator=(AEntity::KeyHook const & rhs)
{
	if (this != &rhs)
	{
		this->_key = rhs.key();
		this->_callback = rhs.callback();
	}
	return (*this);
}

int					AEntity::KeyHook::key(void) const
{
	return (this->_key);
}

AEntity::fKey_t		AEntity::KeyHook::callback(void) const
{
	return (this->_callback);
}
