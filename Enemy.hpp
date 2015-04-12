/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:10 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 11:00:40 by gchateau         ###   ########.fr       //
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

		Enemy &			operator=(Enemy const & rhs);

		void			collision(Entity & target);
		Entity *		clone(void) const;
		char			random(void);

};

#endif
