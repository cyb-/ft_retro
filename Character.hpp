/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:26:02 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 15:39:15 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Entity.hpp"

class	Character : public Entity
{

	public:
		Character(int x,int y, std::string type, char body, int hp, int lives,
			int Points, int vector, int speed);
		Character(Character const & src);
		virtual 	~Character(void);

		 Entity *	shoot();
		virtual Entity *	clone(void) const = 0;
		Character &		operator=(Character const & rhs);
	protected:
		Character(void);

};

#endif
