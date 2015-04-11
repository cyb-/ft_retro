/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:10 by jzimini           #+#    #+#             */
//   Updated: 2015/04/11 22:36:11 by gchateau         ###   ########.fr       //
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
		Entity *		clone(void) const;
		Enemy &			operator=(Enemy const & rhs);
		char			random(void);

};

#endif
