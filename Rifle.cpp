/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rifle.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:28:57 by jzimini           #+#    #+#             */
/*   Updated: 2015/01/11 18:21:35 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rifle.hpp"
#include "Character.hpp"
#include <iostream>


Rifle::Rifle(int x, int y, int Vector) : Entity(x, y, "rifle", '.', 1, 1, 0, Vector)
{
}

Rifle::Rifle(Rifle const & src) : Entity(src.getY(), src.getX(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector())
{
	*this = src;
}

Rifle::~Rifle(void)
{
}

void			Rifle::collision(Entity & target)
{
	(void)target;
}

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

Entity *		Rifle::clone(void) const
{
	Entity *	entity = new Rifle(*this);
	return (entity);
}
