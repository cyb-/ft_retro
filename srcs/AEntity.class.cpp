// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEntity.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/12 16:43:05 by gchateau          #+#    #+#             //
//   Updated: 2015/04/21 00:52:15 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AEntity.class.hpp"

AEntity::AEntity(int x, int y, int vector, int speed, int cHP, int mHP, int damages, int lives, int points, bool collidable) : _posX(x),
																															   _posY(y),
																															   _vector(vector),
																															   _speed(speed),
																															   _cHP(cHP),
																															   _mHP(mHP),
																															   _damages(damages),
																															   _lives(lives),
																															   _points(points),
																															   _collidable(collidable),
																															   _last_move(std::clock()),
																															   _last_shoot(std::clock())
{}

AEntity::AEntity(AEntity const & src) : _posX(src.getX()),
										_posY(src.getY()),
										_vector(src.getVector()),
										_speed(src.getSpeed()),
										_cHP(src.getCHP()),
										_mHP(src.getMHP()),
										_damages(src.getDamages()),
										_lives(src.getLives()),
										_points(src.getPoints()),
										_collidable(src.getCollidable()),
										_last_move(std::clock()),
										_last_shoot(std::clock())
{}

AEntity::~AEntity()
{}

AEntity &	AEntity::operator=(AEntity const & rhs)
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

// ************************************************************************** //
//                                  GETTERS                                   //
// ************************************************************************** //

int				AEntity::getX(void) const
{
	return (this->_posX);
}

int				AEntity::getY(void) const
{
	return (this->_posY);
}

int				AEntity::getVector(void) const
{
	return (this->_vector);
}

int				AEntity::getSpeed(void) const
{
	return (this->_speed);
}

int				AEntity::getCHP(void) const
{
	return (this->_cHP);
}

int				AEntity::getMHP(void) const
{
	return (this->_mHP);
}

int				AEntity::getDamages(void) const
{
	return (this->_damages);
}

int				AEntity::getLives(void) const
{
	return (this->_lives);
}

int				AEntity::getPoints(void) const
{
	return (this->_points);
}

bool			AEntity::getCollidable(void) const
{
	return (this->_collidable);
}

// ************************************************************************** //
//                                  MUTATORS                                  //
// ************************************************************************** //

void			AEntity::setPosition(int x, int y)
{
	this->_posX = x;
	this->_posY = y;
}

void			AEntity::takeDamages(int damages)
{
	this->_cHP -= damages;
	if (this->_cHP <= 0)
		this->die();
}

void			AEntity::die(void)
{
	if (this->_lives > 0)
	{
		this->_cHP = this->_mHP;
		this->_lives -= 1;
	}
	else
	{
		this->_cHP = 0;
		this->_lives = 0;
		this->_last_move = std::clock();
	}
}

// ************************************************************************** //
//                                 MOVEMENTS                                  //
// ************************************************************************** //

bool			AEntity::canMove(void) const
{
	clock_t			current = std::clock();

	if ((current - this->_last_move) < (clock_t)(CLOCKS_PER_SEC / this->_speed))
		return (false);
	return (true);
}

void			AEntity::move(void)
{
	if (this->canMove())
	{
		this->_posY += (this->_vector < 0 ? -1 : 1);
		this->_last_move = std::clock();
	}
}

// ************************************************************************** //
//                                  HELPERS                                   //
// ************************************************************************** //

bool			AEntity::killed(void) const
{
	return ((this->_cHP == 0 && this->_lives == 0 && !this->canMove()) || this->dead());
}

bool			AEntity::dead(void) const
{
	return (this->_cHP == 0 && this->_lives == 0 && this->canMove());
}

bool			AEntity::collision(AEntity *entity)
{
	if (this != entity && this->_vector != entity->getVector() && this->_posX == entity->getX() && this->_posY == entity->getY())
	{
		entity->takeDamages(this->_damages);
		this->takeDamages(entity->getDamages());
//		if (entity->getVector() != this->getVector() && this->_Collidable && entity->getCollidable())
//		{
//			if (!entity->getType().compare("enemy"))
//			{
//				this->setHP(0);
//				entity->looseHP();
//			}
//			else
//			{
//				entity->looseHP();
//				this->looseHP();
//			}
//			return (true);
//		}
//		else if (!entity->getCollidable() != !this->getCollidable())
//		{
//			if (!this->_Collidable && entity->getType() == "rifle")
//				entity->looseHP();
//			else if (!entity->getCollidable() && !this->_Type.compare("rifle"))
//				this->looseHP();
//			return (true);
//		}
	}
	return (false);
}
