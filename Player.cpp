/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:52:16 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 10:59:29 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Rifle.hpp"

Player::Player(void) : Character(0, 0, "player", 94, 1, 3, 0, -1)
{}

Player::Player(Player const & src) : Character(src.getX(), src.getY(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints(), src.getVector())
{
	*this = src;
}

Player::~Player()
{
}

void			Player::collision(Entity & target)
{
	(void) target;
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

Entity *			Player::clone(void) const
{
	Entity *	entity = new Player(*this);
	return (entity);
}
