/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:18:17 by jzimini           #+#    #+#             */
//   Updated: 2015/01/11 20:47:12 by gchateau         ###   ########.fr       //
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

Enemy::Enemy(int x, int y) : Character(x, y, "enemy", random(), 1, 1, 10)
{
	if (_Body == '@')
		_Points += 10;
}

Enemy::Enemy(Enemy const & src) : Character(src.getX(), src.getY(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints())
{
	*this = src;
}

Enemy::~Enemy()
{
}

void			Enemy::collision(Entity & target)
{
	if (_Collidable == true && target.getCollidable() == true
			&& this->_Type != target.getType())
	{
		if (target.getType() == "rifle")
			target.looseLife();
		else if (target.getType() != "rock")
		{
			target.looseHP();
			if (target.getHP() == 0)
				target.looseLife();
		}
	}
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
	}
	return (*this);
}
