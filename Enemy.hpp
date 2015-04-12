/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:10 by jzimini           #+#    #+#             */
/*   Updated: 2015/01/11 18:47:46 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Character.hpp"

class		Enemy : public Character
{

	public:
		Enemy(int x, int y);
		Enemy(Enemy const & src);
		~Enemy(void);

		void			collision(Entity & target);
		Enemy &			operator=(Enemy const & rhs);
		Entity *		clone(void) const;
		char			random(void);

};

#endif
