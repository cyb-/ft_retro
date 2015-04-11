/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:03:08 by jzimini           #+#    #+#             */
//   Updated: 2015/04/11 22:27:05 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_HPP
# define ENTITIES_HPP

#include "Entity.hpp"

class Entities {

public:
	Entities(void);
	Entities(Entities const & src);
	~Entities(void);

	Entities &		operator=(Entities const & rhs);

	Entity *		getEntities(void) const;
	void			push(Entity *entity);

private:
	Entity			*_entities;

	void			_clearEntities(void);

};

#endif
