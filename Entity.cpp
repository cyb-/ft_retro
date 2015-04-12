/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:09:17 by jzimini           #+#    #+#             */
//   Updated: 2015/04/11 17:15:07 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"
//			CONSTRUCTORS		//
Entity::Entity()
{
}

Entity::Entity(int x, int y, std::string type, char body, int hp, int lives, int points, int Vector, int speed) : _PosY(y),
												_PosX(x),
												_Body(body),
												_HP(hp),
												_Lives(lives),
												_Collidable(true),
												_Type(type),
												_Points(points),
												_vector(Vector),
												_speed(speed)
{
	_BodyS += body;
}

Entity::Entity(Entity const & src)
{
	*this = src;
}

Entity::~Entity()
{
}

//		GETORS		//

int				Entity::getY(void) const
{
	return (_PosY);
}

void			Entity::setPosition(int x, int y)
{
	this->_PosX = x;
	this->_PosY = y;
}

int				Entity::getX(void) const
{
	return (_PosX);
}

int				Entity::getLives(void) const
{
	return (_Lives);
}

int				Entity::getHP(void) const
{
	return (_HP);
}

std::string		Entity::getType(void) const
{
	return (_Type);
}

bool			Entity::getCollidable(void) const
{
	return (_Collidable);
}

char			Entity::getBody(void) const
{
	return (_Body);
}

void			Entity::setBody(char body)
{
	_Body = body;
}

std::string		Entity::getBodyS(void) const
{
	return (_BodyS);
}

int				Entity::getPoints(void) const
{
	return (_Points);
}

int				Entity::getVector(void) const
{
	return (_vector);
}

int				Entity::getSpeed(void) const
{
	return (_speed);
}

//				SETORS & METHODS		//

void			Entity::looseHP(void)
{
	_HP -= 1;
	if (_Body == 'W' && _HP > 0)
		this->setBody('V');
	else if (_HP <= 0)
		this->looseLife();
}
void			Entity::looseLife(void)
{
	_Lives -= 1;
	this->setBody('*');
}

void			Entity::setHP(int i)
{
	_HP = i;
	if (_HP <= 0)
		this->looseLife();
}

void			Entity::move(std::string direction)
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

void			Entity::move()
{
	_PosY += _vector;
}

bool			Entity::collision(Entity *entity)
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

Entity &		Entity::operator=(Entity const & rhs)
{
	if (this != &rhs)
	{
		this->_PosY = rhs.getY();
		this->_PosX = rhs.getX();
		this->_Type = rhs.getType();
		this->_Body = rhs.getBody();
		this->_BodyS = rhs.getBodyS();
	}
	return (*this);
}
