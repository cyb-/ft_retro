// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:47:13 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 17:21:41 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include "IState.interface.hpp"
# include "Entities.class.hpp"
# include "Player.hpp"

# include <ctime>

class Game : public IState
{

public:
	Game(void);
	Game(Game const & src);
	~Game(void);

	Game &	operator=(Game const & rhs);

	void				init(Screen *screen);
	void				handle(Screen *screen);
	void				update(Screen *screen);
	void				render(Screen *screen);

	unsigned int		getLoops(void) const;
	unsigned int		getScore(void) const;
	Player const &		getPlayer(void) const;
	Entities const &	getEntities(void) const;

private:
	void				_displayUI(Screen *screen) const;
	void				_generateWave(Screen *screen);
	void				_checkCollision(AEntity *entity);

	Player				_player;
	Entities			_entities;
	unsigned int		_loops;
	unsigned int		_score;
	clock_t				_last_wave;
	clock_t				_game_start;

	static int			_wavesPerSec;
	static int			_wavesDelay;
	static int			_UIHeight;

};

#endif
