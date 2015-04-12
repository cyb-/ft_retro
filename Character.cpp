/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:45:16 by jzimini           #+#    #+#             */
//   Updated: 2015/01/11 17:20:35 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Screen.class.hpp"
#include "Character.hpp"
#include "Rifle.hpp"

Character::Character(void) : Entity()
{
}

Character::Character(int x, int y, std::string type, char body, int hp, int lives,
					int points, int vector) : Entity(x, y, type, body, hp, lives,
					points, vector)
{
}

Character::Character(Character const & src) : Entity(src.getY(), src.getX(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector())
{
	*this = src;
}

Character::~Character(void)
{
}

Entity*		Character::shoot()
{
	Entity	*rifle = new Rifle(_PosX, _PosY - 1, _vector);
	return (rifle);
}

Character &		Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		_PosY = rhs.getY();
		_PosX = rhs.getX();
		_Type = rhs.getType();
		_HP = rhs.getHP();
	}
	return *this;
}
