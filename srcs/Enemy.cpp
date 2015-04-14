/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:18:17 by jzimini           #+#    #+#             */
//   Updated: 2015/04/14 02:30:11 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Rifle.hpp"

#include <cstdlib>
#include <iostream>

int		Enemy::_shootDelay = 4;

char			Enemy::random(void)
{
	int				i;
	char			type[2] = {'V', 'W'};

	srand((int)clock());
	i = rand() % 2;
	return (type[i]);
}

Enemy::Enemy(int x, int y) : AEntity(x, y, "enemy", random(), 1, 1, 10, 1, 3)
{
	if (_Body == 'W')
	{
		_Points += 10;
		_HP = 2;
		_speed = 2;
	}
}

Enemy::Enemy(Enemy const & src) : AEntity(src.getX(), src.getY(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector(), src.getSpeed())
{
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy &			Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		_PosY = rhs.getY();
		_PosX = rhs.getX();
		_Type = rhs.getType();
		_Body = rhs.getBody();
		_HP = rhs.getHP();
		_Points = rhs.getPoints();
		_vector = rhs.getVector();
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

	if (this->_Body == 'V'
		&& ((std::rand() % 180 + 8) % 2) == 0
		&& (current - this->_last_shoot > (clock_t)(CLOCKS_PER_SEC * Enemy::_shootDelay)))
	{
		rifle = new Rifle(_PosX, _PosY + _vector, _vector);
		this->_last_shoot = current;
	}
	return (rifle);
}
