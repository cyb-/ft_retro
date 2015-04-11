/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:03:08 by jzimini           #+#    #+#             */
/*   Updated: 2015/04/11 13:03:09 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_HPP
# define ENTITIES_HPP

#include "Entity.hpp"

class Entities {

public:
	Entities();
	~Entities(void);

	Entity *		getEntities(void) const;
	int				getCount(void) const;

	Entities &	operator=(Entities const & rhs);

private:
	static int			_count;
	Entity			*_entities;

	Entities(Entities const & src);

};

#endif
