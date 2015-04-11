/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rock.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:28:57 by jzimini           #+#    #+#             */
//   Updated: 2015/04/11 22:38:39 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Rock.hpp"

Rock::Rock(int x, int y) : Entity(x, y, "rock", 'O', 1, 1, 0)
{
	_Collidable = false;
}

Rock::Rock(Rock const & src) : Entity(src.getY(), src.getX(), src.getType(),
		src.getBody(), src.getHP(), src.getLives(), src.getPoints())
{
	*this = src;
}

Rock::~Rock(void)
{
}

void			Rock::collision(Entity & target)
{
	if (this->_Collidable == true && target.getCollidable() == true
			&& target.getType() != "rifle")
	{
		target.looseHP() ;
		if (target.getHP() == 0)
			target.looseLife();
	}
	else if (target.getType() == "rifle")
		target.looseLife();
}

Rock &			Rock::operator=(Rock const & rhs)
{
	if (this != &rhs)
	{
		_PosY = rhs.getY();
		_PosX = rhs.getX();
		_Body = rhs.getBody();
		_Collidable = rhs.getCollidable();
		_Type = rhs.getType();
		_Lives = rhs.getLives();
		_HP = rhs.getHP();
		_Collidable = rhs.getCollidable();
	}
	return *this;
}

Entity *		Rock::clone(void) const
{
	Entity *	entity = new Rock(*this);
	return (entity);
}
