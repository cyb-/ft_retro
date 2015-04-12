/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rock.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:26:02 by jzimini           #+#    #+#             */
/*   Updated: 2015/01/11 12:51:43 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROCK_HPP
# define ROCK_HPP

# include "Entity.hpp"

class	Rock : public Entity
{

	public:
		Rock(int x, int y);
		Rock(Rock const & src);
		~Rock(void);

		void		collision(Entity & target);
		Entity *	clone(void) const;
		Rock &		operator=(Rock const & rhs);


};

#endif
