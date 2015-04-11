/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:03:16 by jzimini           #+#    #+#             */
/*   Updated: 2015/04/11 13:03:18 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Entities.hpp"

Entities::Entities(){}

Entities::~Entities(){}

Entity *	Entities::getEntities(void) const{
	return (_entities);
}

int				Entities::getCount(void) const {
	return (_count);
}

Entities &		Entities::operator=(Entities const & rhs){
	if (this != &rhs)
	{
		_entities = rhs.getEntities();
		_count = rhs.getCount();
	}
	return (*this);
}

int		Entities::_count;