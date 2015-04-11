/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:10 by jzimini           #+#    #+#             */
/*   Updated: 2015/01/11 12:23:38 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Character.hpp"

class		Player : public Character
{

	public:
		Player(void);
		Player(Player const & src);
		~Player(void);

		void			collision(Entity & target);
		Player &		operator=(Player const & rhs);

	private:

};

#endif
