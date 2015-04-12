/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rifle.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:26:02 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 16:50:44 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef RIFLE_HPP
# define RIFLE_HPP

# include "AEntity.class.hpp"

class	Rifle : public AEntity
{

	public:
		Rifle(int x, int y, int vector);
		Rifle(Rifle const & src);
		~Rifle(void);

		Rifle &		operator=(Rifle const & rhs);

		AEntity *	clone(void) const;
		AEntity *	shoot(void);

	private:
		Rifle();
};

#endif
