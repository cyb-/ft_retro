// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Entities.class.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 22:43:55 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 00:54:11 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENTITIES_CLASS_HPP
# define ENTITIES_CLASS_HPP

#include "Entity.hpp"

class Entities
{

public:
	Entities(void);
	Entities(Entities const & src);
	~Entities(void);

	Entities &	operator=(Entities const & rhs);

	class Item
	{

	public:
		Item(void);
		Item(Item const & src);
		Item(Entity *entity);
		~Item(void);

		Item &		operator=(Item const & rhs);

		int			getIndex(void) const;
		Entity *	getEntity(void) const;
		Item *		getNext(void) const;
		Item *		getPrev(void) const;

		void		setNext(Item *item);
		void		setPrev(Item *item);

		bool		hasEntity(void) const;
		bool		hasNext(void) const;
		bool		hasPrev(void) const;

	private:
		int			_index;
		Entity *	_entity;
		Item *		_next;
		Item *		_prev;

		static int	_nbInst;

	};

	int			getCount(void) const;
	Item *		getItems(void) const;
	void		push(Entity *entity);

private:
	void		_clearItems(void);

	int				_count;
	Item			*_items;

};

#endif
