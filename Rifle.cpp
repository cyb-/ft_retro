/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rifle.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:28:57 by jzimini           #+#    #+#             */
//   Updated: 2015/04/11 22:39:36 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Rifle.hpp"
#include "Character.hpp"
#include <iostream>


Rifle::Rifle(int x, int y, Character & shooter) : Entity(x, y, "rifle", '.', 1, 1, 0),
												_Shooter(shooter)
{
}

Rifle::Rifle(Rifle const & src) : Entity(src.getY(), src.getX(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints()),
								_Shooter(src.getShooter())
{
	*this = src;
}

Rifle::~Rifle(void)
{
}

Character &		Rifle::getShooter(void) const
{
	return (_Shooter);
}

std::string		Rifle::getShooterType(void) const
{
	return		(_Shooter.getType());
}

void			Rifle::collision(Entity & target)
{
	if (this->_Collidable == true && target.getCollidable() == true
		&& target.getType() != this->getShooterType())
	{
		target.looseHP() ;
		if (target.getHP() <= 0)
			target.looseLife();
		std::cout << this->getShooterType() << std::endl;
		if (this->getShooterType().compare("player") == 0)
			_Shooter.setScore(target.getPoints());
		std::cout << _Shooter.getScore() << std::endl;
	}
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
		_Shooter = rhs.getShooter();
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
