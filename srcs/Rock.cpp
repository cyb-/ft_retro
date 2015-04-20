/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rock.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:28:57 by jzimini           #+#    #+#             */
//   Updated: 2015/04/21 01:11:05 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Rock.hpp"

Rock::Rock(int x, int y) : AEntity(x, y, 1, 2, 1, 1, 0, 1, 0, false)
{}

Rock::Rock(Rock const & src) : AEntity(src.getY(), src.getX(), src.getVector(), src.getSpeed(), src.getCHP(), src.getMHP(), src.getDamages(), src.getLives(), src.getPoints(), src.getCollidable())
{}

Rock::~Rock(void)
{
}

Rock &			Rock::operator=(Rock const & rhs)
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
	return *this;
}

AEntity *		Rock::clone(void) const
{
	AEntity *	entity = new Rock(*this);
	return (entity);
}

AEntity *		Rock::shoot(void)
{
	return (0);
}

int				Rock::getBody(void) const
{
	return ('O');
}
