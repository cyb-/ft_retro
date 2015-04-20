/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rock.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:26:02 by jzimini           #+#    #+#             */
//   Updated: 2015/04/21 00:43:54 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef ROCK_HPP
# define ROCK_HPP

# include "AEntity.class.hpp"

class Rock : public AEntity
{

public:
	Rock(int x, int y);
	Rock(Rock const & src);
	~Rock(void);

	Rock &		operator=(Rock const & rhs);

	AEntity *	clone(void) const;
	AEntity *	shoot(void);

	int			getBody(void) const;

};

#endif
