/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:18:17 by jzimini           #+#    #+#             */
//   Updated: 2015/04/21 01:17:37 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Rifle.hpp"

#include <cstdlib>
#include <iostream>

int		Enemy::_shootDelay = 4;

Enemy::Enemy(int x, int y) : AEntity(x, y, 1, 3, 50, 50, 50, 1, 50, true)
{
	int			rd[2] = {'V', 'W'};

	this->_body = rd[std::rand() % 2];
	if (this->_body == 'W')
	{
		this->_points += 10;
		this->_cHP = 2;
		this->_speed = 2;
	}
}

Enemy::Enemy(Enemy const & src) : AEntity(src.getX(), src.getY(), src.getVector(), src.getSpeed(), src.getCHP(), src.getMHP(), src.getDamages(), src.getLives(), src.getPoints(), src.getCollidable())
{}

Enemy::~Enemy()
{}

Enemy &			Enemy::operator=(Enemy const & rhs)
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
	return (*this);
}

AEntity *		Enemy::clone(void) const
{
	AEntity *	entity = new Enemy(*this);
	return (entity);
}

AEntity *		Enemy::shoot(void)
{
	AEntity			*rifle = 0;
	clock_t			current = std::clock();

	if (this->_body == 'V'
		&& ((std::rand() % 180 + 8) % 2) == 0
		&& (current - this->_last_shoot > (clock_t)(CLOCKS_PER_SEC * Enemy::_shootDelay)))
	{
		rifle = new Rifle(this->_posX, this->_posY + this->_vector, this->_vector);
		this->_last_shoot = current;
	}
	return (rifle);
}

int				Enemy::getBody(void) const
{
	if (this->killed())
		return ('*');
	return (this->_body);
}
