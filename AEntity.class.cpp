// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEntity.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/12 16:43:05 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 16:43:34 by gchateau         ###   ########.fr       //
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
																												  _last_move(std::clock())
{}

AEntity::AEntity(AEntity const & src) : _last_move(std::clock())
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

void			AEntity::setBody(char body)
{
	_Body = body;
}

int				AEntity::getPoints(void) const
{
	return (_Points);
}

int				AEntity::getVector(void) const
{
	return (_vector);
}

int				AEntity::getSpeed(void) const
{
	return (_speed);
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

//				SETORS & METHODS		//

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

void			AEntity::move(std::string direction)
{
	int			i;

	i = 1;
	if (this->getType().compare("rifle") == 0)
		i = 2;
	if (direction.compare("up") == 0)
		_PosY -= i;
	else if (direction.compare("down") == 0)
		_PosY += i;
	else if (direction.compare("right") == 0)
		_PosX += i;
	else if (direction.compare("left") == 0)
		_PosX -= i;
}

void			AEntity::move(void)
{
	clock_t			current = std::clock();

	if ((current - this->_last_move) > (clock_t)(CLOCKS_PER_SEC / this->_speed))
	{
		_PosY += _vector;
		this->_last_move = current;
	}
}

bool			AEntity::collision(AEntity *entity)
{
	if (this != entity && this->_PosX == entity->getX() && this->_PosY == entity->getY()
		&& entity->getVector() != this->getVector())
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
	return (false);
}
