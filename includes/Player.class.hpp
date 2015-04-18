// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/18 02:25:49 by gchateau          #+#    #+#             //
//   Updated: 2015/04/18 02:26:00 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

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
	Player &		operator+=(int score);
	Player &		operator-=(int hp);

	int				getScore(void) const;
	void			respawn(int x, int y);

	AEntity *		clone(void) const;
	AEntity *		shoot(void);

	void			attack(Screen *screen, Game *game);
	void			escape(Screen *screen, Game *game);
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

private:
	int				_score;

};

#endif
