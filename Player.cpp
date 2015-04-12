/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:52:16 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 17:05:35 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Rifle.hpp"

Player::Player(void) : ACharacter(0, 0, "player", 94, 2, 3, 0, -1, 1)
{}

Player::Player(Player const & src) : ACharacter(src.getX(), src.getY(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector(), src.getSpeed())
{
	*this = src;
}

Player::~Player()
{
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
		_Lives = rhs.getLives();
	}
	return (*this);
}

void				Player::respawn(int x, int y)
{
	if (_Lives > 0)
		_HP = 2;
	this->setBody(94);
	this->setPosition(x, y);
}

AEntity *			Player::clone(void) const
{
	AEntity *	entity = new Player(*this);
	return (entity);
}
