/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:52:16 by jzimini           #+#    #+#             */
//   Updated: 2015/04/11 18:23:10 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Rifle.hpp"

Player::Player(void) : Character(0, 0, "player", 94, 1, 3, 0)
{
}

Player::Player(Player const & src) : Character(src.getX(), src.getY(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints())
{
	*this = src;
}

Player::~Player()
{
}

void			Player::collision(Entity & target)
{
	if (this->_Collidable == true && target.getCollidable() == true
			&& this->_Type != target.getType())
	{
		if (target.getType() == "rifle")
			target.looseLife();
		else if (target.getType() != "rock")
		{
			target.looseHP();
			if (target.getHP() <= 0)
			{
				target.looseLife();
				_Score += target.getPoints();
			}
		}
	}
}

Player &			Player::operator=(Player const & rhs)
{
	if (this != &rhs)
	{
		_PosY = rhs.getY();
		_PosX = rhs.getX();
		_Type = rhs.getType();
		_Body = rhs.getBody();
		_HP = rhs.getHP();
		_Score = rhs.getScore();
		_Lives = rhs.getLives();
	}
	return (*this);
}
