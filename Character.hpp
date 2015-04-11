/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:26:02 by jzimini           #+#    #+#             */
/*   Updated: 2015/01/11 18:13:53 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Entity.hpp"

class	Character : public Entity
{

	public:
		Character(int x,int y, std::string type, char body, int hp, int lives, int Points);
		Character(Character const & src);
		Entity *	shoot();
		virtual 	~Character(void);

		int				getScore(void) const;
		void			setScore(int i);

		virtual void	collision(Entity & target) = 0;
		Character &		operator=(Character const & rhs);
	protected :
		Character(void);
		int				_Score;


};

#endif
