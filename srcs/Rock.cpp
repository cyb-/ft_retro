/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rock.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:28:57 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 17:07:28 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Rock.hpp"

Rock::Rock(int x, int y) : AEntity(x, y, "rock", 'O', 1, 1, 5, 1, 1)
{
	_Collidable = false;
}

Rock::Rock(Rock const & src) : AEntity(src.getY(), src.getX(), src.getType(), src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector(), src.getSpeed())
{}

Rock::~Rock(void)
{
}

Rock &			Rock::operator=(Rock const & rhs)
{
	if (this != &rhs)
	{
		_PosY = rhs.getY();
		_PosX = rhs.getX();
		_Body = rhs.getBody();
		_Collidable = rhs.getCollidable();
		_Type = rhs.getType();
		_Lives = rhs.getLives();
		_HP = rhs.getHP();
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
