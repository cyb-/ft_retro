/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:18:17 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 17:05:06 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <cstdlib>
#include <iostream>

char			Enemy::random(void)
{
	int				i;
	char			type[2] = {'V', 'W'};

	srand((int)clock());
	i = rand() % 2;
	return (type[i]);
}

Enemy::Enemy(int x, int y) : ACharacter(x, y, "enemy", random(), 1, 1, 10, 1, 2)
{
	if (_Body == 'W')
	{
		_Points += 10;
		_HP = 2;
		_speed = 2;
	}
}

Enemy::Enemy(Enemy const & src) : ACharacter(src.getX(), src.getY(), src.getType(),
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
