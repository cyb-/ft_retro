/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:10 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 16:49:06 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "ACharacter.class.hpp"

class		Enemy : public ACharacter
{

	public:
		Enemy(int x, int y);
		Enemy(Enemy const & src);
		~Enemy(void);

		Enemy &			operator=(Enemy const & rhs);

		AEntity *		clone(void) const;
		char			random(void);

};

#endif
