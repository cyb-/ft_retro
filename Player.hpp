/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:10 by jzimini           #+#    #+#             */
//   Updated: 2015/04/12 16:51:17 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "ACharacter.class.hpp"

class		Player : public ACharacter
{

	public:
		Player(void);
		Player(Player const & src);
		~Player(void);

		int				getScore(void) const;
		void			setScore(int i);
		void			respawn(int x, int y);

		AEntity *		clone(void) const;
		Player &		operator=(Player const & rhs);
};

#endif
