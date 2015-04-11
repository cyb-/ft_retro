/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:09:17 by jzimini           #+#    #+#             */
/*   Updated: 2015/01/11 21:04:09 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"
//			CONSTRUCTORS		//
Entity::Entity()
{
}

Entity::Entity(int x, int y, std::string type, char body, int hp, int lives, int points) : _PosY(y),
												_PosX(x),
												_Body(body),
												_HP(hp),
												_Lives(lives),
												_Collidable(true),
												_Type(type),
												_Points(points)
{
	_BodyS += body;
	next = NULL;
	prev = NULL;
}

Entity::Entity(Entity const & src)
{
	*this = src;
}

Entity::~Entity()
{
	if (prev && next)
	{
		next->prev = prev;
		prev->next = next;
	}
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

Entity *		Entity::getNext(void)	const
{
	return (next);
}

Entity *		Entity::getPrev(void)	const
{
	return (prev);
}

//				SETORS & METHODS		//

void			Entity::looseHP(void)
{
	_HP -= 1;
}
void			Entity::looseLife(void)
{
	_Lives -= 1;
	if (_Lives > 0)
		_HP = 1;
}

void			Entity::move(std::string direction)
{
	int			i;

	i = 1;
	if (this->getType().compare("rifle") == 0)
		i = 2;
	else if (direction.compare("up") == 0)
		_PosY -= i;
	else if (direction.compare("down") == 0)
		_PosY += i;
	else if (direction.compare("right") == 0)
		_PosX += i;
	else if (direction.compare("down") == 0)
		_PosX -= i;
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
		this->prev = rhs.prev;
		this->next = rhs.next;
	}
	return (*this);
}
