/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:03:08 by jzimini           #+#    #+#             */
//   Updated: 2015/04/11 18:16:35 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_HPP
# define ENTITIES_HPP

#include "Entity.hpp"

class Entities {

public:
	Entities(void);
	~Entities(void);

	Entity *		getEntities(void) const;
	void			push(Entity *entity);

	Entities &	operator=(Entities const & rhs);

private:
	Entity			*_entities;

	void			_clearEntities(void);

	Entities(Entities const & src);

};

#endif
