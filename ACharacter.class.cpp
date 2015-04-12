// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ACharacter.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/12 16:46:44 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 17:04:33 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ACharacter.class.hpp"
#include "Rifle.hpp"

#include <cstdlib>

int		ACharacter::_shootDelay = 8;

ACharacter::ACharacter(int x, int y, std::string type, char body, int hp, int lives, int points, int vector, int speed) : AEntity(x, y, type, body, hp, lives, points, vector, speed)
{}

ACharacter::ACharacter(ACharacter const & src) : AEntity(src.getY(), src.getX(), src.getType(), src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector(), src.getSpeed())
{}

ACharacter::~ACharacter(void)
{}

ACharacter &	ACharacter::operator=(ACharacter const & rhs)
{
	if (this != &rhs)
	{
		_PosY = rhs.getY();
		_PosX = rhs.getX();
		_Type = rhs.getType();
		_HP = rhs.getHP();
	}
	return (*this);
}

AEntity *		ACharacter::shoot(void)
{	
	AEntity			*rifle = 0;
	clock_t			current = std::clock();

	if (this->_Type == "player" || (this->_Body == 'V' && (current - this->_last_shoot > (clock_t)(CLOCKS_PER_SEC * ACharacter::_shootDelay) && (std::rand() % 180 + 8) % 3 == 0)))
	{
		rifle = new Rifle(_PosX, _PosY + _vector, _vector);
		this->_last_shoot = current;
	}
	return (rifle);
}
