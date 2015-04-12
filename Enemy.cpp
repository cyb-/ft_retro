/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:18:17 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 11:02:08 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <cstdlib>
#include <iostream>

char			Enemy::random(void)
{
	int				i;
	char			type[2] = {'V', '@'};

	srand((int)clock());
	i = rand() % 2;
	return (type[i]);
}

Enemy::Enemy(int x, int y) : Character(x, y, "enemy", random(), 1, 1, 10, 1)
{
	if (_Body == '@')
		_Points += 10;
}

Enemy::Enemy(Enemy const & src) : Character(src.getX(), src.getY(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector())
{
	*this = src;
}

Enemy::~Enemy()
{
}

void			Enemy::collision(Entity & target)
{
	(void)target;
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

Entity *		Enemy::clone(void) const
{
	Entity *	entity = new Enemy(*this);
	return (entity);
}
