/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:45:16 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 15:41:30 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Rifle.hpp"

Character::Character(int x, int y, std::string type, char body, int hp, int lives,
					int points, int vector, int speed) : Entity(x, y, type, body, hp, lives,
					points, vector, speed)
{}

Character::Character(Character const & src) : Entity(src.getY(), src.getX(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector(), src.getSpeed())
{
	*this = src;
}

Character::~Character(void)
{}

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

Entity *		Character::shoot()
{
	Entity	*rifle = new Rifle(_PosX, _PosY - 1, _vector);
	return (rifle);
}
