/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rifle.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:28:57 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 15:42:46 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Rifle.hpp"
#include "Character.hpp"

Rifle::Rifle(int x, int y, int Vector) : Entity(x, y + Vector, "rifle", '.', 1, 1, 0, Vector, 4)
{}

Rifle::Rifle(Rifle const & src) : Entity(src.getY(), src.getX(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector(), src.getSpeed())
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

Entity *		Rifle::clone(void) const
{
	Entity *	entity = new Rifle(*this);
	return (entity);
}

Entity *		Rifle::shoot(){
	return (0);
}
