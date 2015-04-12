/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rifle.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:28:57 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 17:06:47 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Rifle.hpp"

Rifle::Rifle(int x, int y, int Vector) : AEntity(x, y + Vector, "rifle", '.', 1, 1, 0, Vector, 4)
{
	if (Vector > 0)
		_Body = '|';
	if (Vector < 0)
		_speed = 6;
}
Rifle::Rifle(Rifle const & src) : AEntity(src.getX(), src.getY(), src.getType(), src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector(), src.getSpeed())
{}

Rifle::~Rifle(void)
{}

Rifle &			Rifle::operator=(Rifle const & rhs)
{
	if (this != &rhs)
	{
		_PosY = rhs.getY();
		_PosX = rhs.getX();
		_Body = rhs.getBody();
		_Collidable = rhs.getCollidable();
		_Type = rhs.getType();
		_vector = rhs.getVector();
		_Lives = rhs.getLives();
		_HP = rhs.getHP();
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
