/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:10 by jzimini           #+#    #+#             */
//   Updated: 2015/04/13 03:24:47 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "ACharacter.class.hpp"

class Player : public ACharacter
{

public:
	Player(void);
	Player(Player const & src);
	~Player(void);

	Player &		operator=(Player const & rhs);

	int				getScore(void) const;
	void			setScore(int i);
	void			respawn(int x, int y);

	AEntity *		clone(void) const;

};

#endif
