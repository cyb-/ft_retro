/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rifle.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:28:57 by jzimini           #+#    #+#             */
//   Updated: 2015/04/21 01:16:46 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Rifle.hpp"

Rifle::Rifle(int x, int y, int vector) : AEntity(x, y + vector, vector, 4, 1, 1, 50, 1, 30, true)
{}

Rifle::Rifle(Rifle const & src) : AEntity(src.getX(), src.getY(), src.getVector(), src.getSpeed(), src.getCHP(), src.getMHP(), src.getDamages(), src.getLives(), src.getPoints(), src.getCollidable())
{}

Rifle::~Rifle(void)
{}

Rifle &			Rifle::operator=(Rifle const & rhs)
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

AEntity *		Rifle::clone(void) const
{
	AEntity *	entity = new Rifle(*this);
	return (entity);
}

AEntity *		Rifle::shoot(void)
{
	return (0);
}

int				Rifle::getBody(void) const
{
	if (this->killed())
		return ('*');
	return ('.');
}
