// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Entities.class.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 22:46:24 by gchateau          #+#    #+#             //
//   Updated: 2015/04/17 23:50:06 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

# include "Entities.class.hpp"

Entities::Entities(void) : _count(0), _items(0)
{}

Entities::Entities(Entities const & src) : _count(0), _items(0)
{
	*this = src;
}

Entities::~Entities(void)
{
	this->_clearItems();
}

Entities &			Entities::operator=(Entities const & rhs)
{
	Entities::Item *	tmp;

	if (this != &rhs)
	{
		this->_clearItems();
		tmp = rhs.getItems();
		while (tmp)
		{
			if (tmp->hasEntity())
				this->push(tmp->getEntity()->clone());
			tmp = tmp->getNext();
		}
	}
	return (*this);
}

int					Entities::getCount(void) const
{
	return (this->_count);
}

Entities::Item *	Entities::getItems(void) const
{
	return (this->_items);
}

void				Entities::push(AEntity *entity)
{
	Entities::Item *	tmp;
	Entities::Item *	item;

	if (entity == 0)
		return ;
	if ((item = new Entities::Item(entity)) == 0)
		return ;
	if (this->_items != 0)
	{
		tmp = this->_items;
		while (tmp->getNext())
			tmp = tmp->getNext();
		item->setPrev(tmp);
		tmp->setNext(item);
	}
	else
		this->_items = item;
	this->_count++;
}

void				Entities::remove(int index)
{
	Entities::Item *	del;

	if (this->_items == 0)
		return ;
	if (index == this->_items->getIndex())
	{
		del = this->_items;
		this->_items = del->getNext();
		delete del;
		this->_count--;
	}
	else
	{
		del = this->_items;
		while (del && del->getIndex() != index)
			del = del->getNext();
		if (del != 0)
		{
			delete del;
			this->_count--;
		}
	}
}

void				Entities::remove(AEntity *entity)
{
	Entities::Item *	tmp;

	tmp = this->_items;
	while (tmp && tmp->getEntity() != entity)
		tmp = tmp->getNext();
	if (tmp != 0)
		this->remove(tmp->getIndex());
}

void				Entities::_clearItems(void)
{
	Entities::Item *	tmp;

	while (this->_items)
	{
		tmp = this->_items;
		this->_items = tmp->getNext();
		delete tmp;
	}
	this->_count = 0;
}

// ************************************************************************** //
//                               Entities::Item                               //
// ************************************************************************** //

int		Entities::Item::_nbInst = 0;

Entities::Item::Item(void) : _index(Entities::Item::_nbInst),
							 _entity(0),
							 _next(0),
							 _prev(0)
{
	Entities::Item::_nbInst++;
}

Entities::Item::Item(Item const & src) : _index(Entities::Item::_nbInst),
										 _entity(src.getEntity()->clone()),
										 _next(0),
										 _prev(0)
{
	Entities::Item::_nbInst++;
}

Entities::Item::Item(AEntity *entity) : _index(Entities::Item::_nbInst),
									   _entity(entity),
									   _next(0),
									   _prev(0)
{
	Entities::Item::_nbInst++;
}

Entities::Item::~Item(void)
{
	if (this->hasEntity())
		delete this->_entity;
	if (this->hasPrev())
		this->_prev->setNext(this->_next);
	if (this->hasNext())
		this->_next->setPrev(this->_prev);
}

Entities::Item &	Entities::Item::operator=(Entities::Item const & rhs)
{
	if (this != &rhs)
	{
		delete this->_entity;
		if (rhs.hasEntity())
			this->_entity = rhs.getEntity()->clone();
		this->_next = rhs.getNext();
		this->_prev = rhs.getPrev();
	}
	return (*this);
}

int					Entities::Item::getIndex(void) const
{
	return (this->_index);
}

AEntity *			Entities::Item::getEntity(void) const
{
	return (this->_entity);
}

Entities::Item *	Entities::Item::getNext(void) const
{
	return (this->_next);
}

Entities::Item *	Entities::Item::getPrev(void) const
{
	return (this->_prev);
}

void				Entities::Item::setNext(Item *item)
{
	this->_next = item;
}

void				Entities::Item::setPrev(Item *item)
{
	this->_prev = item;
}

bool				Entities::Item::hasEntity(void) const
{
	if (this->_entity != 0)
		return (true);
	return (false);
}

bool				Entities::Item::hasNext(void) const
{
	if (this->_next != 0)
		return (true);
	return (false);
}

bool				Entities::Item::hasPrev(void) const
{
	if (this->_prev != 0)
		return (true);
	return (false);
}
