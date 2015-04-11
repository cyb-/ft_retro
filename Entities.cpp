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

Entities &		Entities::operator=(Entities const & rhs){
	if (this != &rhs)
	{
		_entities = rhs.getEntities();
	}
	return (*this);
}