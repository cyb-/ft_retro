/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:10 by jzimini           #+#    #+#             */
//   Updated: 2015/04/14 02:28:21 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AEntity.class.hpp"

class Enemy : public AEntity
{

public:
	Enemy(int x, int y);
	Enemy(Enemy const & src);
	~Enemy(void);

	Enemy &			operator=(Enemy const & rhs);

	AEntity *		shoot(void);
	AEntity *		clone(void) const;
	char			random(void);

private:
	Enemy(void);

	static int _shootDelay;

};

#endif
