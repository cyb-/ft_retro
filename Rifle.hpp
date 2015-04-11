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
		Rifle(int x, int y, Character & shooter);
		Rifle(Rifle const & src);
		~Rifle(void);

		std::string	getShooterType(void) const;
		Character &	getShooter(void) const;
		void		collision(Entity & target);
		Rifle &		operator=(Rifle const & rhs);
	private:
		Character &		_Shooter;
};

#endif
