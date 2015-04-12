/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rifle.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:26:02 by jzimini           #+#    #+#             */
/*   Updated: 2015/01/11 15:49:28 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RIFLE_HPP
# define RIFLE_HPP

# include "Entity.hpp"
# include "Character.hpp"

class	Rifle : public Entity
{

	public:
		Rifle(int x, int y, int vector);
		Rifle(Rifle const & src);
		~Rifle(void);

		void		collision(Entity & target);
		Entity *	clone(void) const;

		Rifle &		operator=(Rifle const & rhs);
};

#endif
