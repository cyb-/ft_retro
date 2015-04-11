/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:03:16 by jzimini           #+#    #+#             */
//   Updated: 2015/04/11 18:24:02 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

# include "Entities.hpp"

Entities::Entities(void) : _entities(0)
{}

Entities::~Entities(void)
{
	this->_clearEntities();
}

Entities &		Entities::operator=(Entities const & rhs)
{
	if (this != &rhs)
	{
		// CHANGE THIS !!!!!!!!!
		_entities = rhs.getEntities();
	}
	return (*this);
}

Entity *		Entities::getEntities(void) const
{
	return (this->_entities);
}

void			Entities::push(Entity *entity)
{
	Entity			*tmp;

	if (entity == 0)
		return ;
	if (this->_entities != 0)
	{
		tmp = this->_entities;
		while (tmp->getNext())
			tmp = tmp->getNext();
		entity->setPrev(tmp);
		tmp->setNext(entity);
	}
	else
		this->_entities = entity;
}

void			Entities::_clearEntities(void)
{
	Entity			*tmp;

	if (this->_entities != 0)
	{
		while (this->_entities)
		{
			tmp = this->_entities;
			this->_entities = tmp->getNext();
			delete tmp;
		}
	}
}
