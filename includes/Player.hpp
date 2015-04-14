/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:10 by jzimini           #+#    #+#             */
//   Updated: 2015/04/14 03:12:45 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Screen.class.hpp"
# include "AEntity.class.hpp"

class Game;

class Player : public AEntity
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
	AEntity *		shoot(void);

	void			moveUp(Screen *screen, Game *game);
	void			moveDown(Screen *screen, Game *game);
	void			moveLeft(Screen *screen, Game *game);
	void			moveRight(Screen *screen, Game *game);

	typedef	void	(Player::*fKey_t) (Screen *, Game *);

	struct KeyHook
	{

	public:
		KeyHook(void);
		KeyHook(int key, fKey_t callback);
		KeyHook(KeyHook const & src);
		~KeyHook(void);

		KeyHook &	operator=(KeyHook const & rhs);
		bool		operator==(int key);

		int			key(void) const;
		fKey_t		callback(void) const;

	private:
		int			_key;
		fKey_t		_callback;

	};

};

#endif
