/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rifle.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:26:02 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 10:58:14 by gchateau         ###   ########.fr       //
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

		Entity *	clone(void) const;

		Rifle &		operator=(Rifle const & rhs);
	private:
		Rifle();
};

#endif
