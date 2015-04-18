// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:47:13 by gchateau          #+#    #+#             //
//   Updated: 2015/04/18 03:15:00 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include "IState.interface.hpp"
# include "Entities.class.hpp"
# include "Player.class.hpp"

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

	Player const &		getPlayer(void) const;
	Entities const &	getEntities(void) const;

	unsigned int		getBestScore(void) const;
	unsigned int		getLastScore(void) const;
	void				setLastScore(unsigned int score);

	void				addEntity(AEntity *entity);
	void				delEntity(AEntity *entity);
	void				delEntity(int index);

private:
	bool				_canGenerateWave(void);
	void				_displayUI(Screen *screen) const;
	void				_generateWave(Screen *screen);
	void				_checkPlayer(Screen *screen);
	void				_checkCollision(AEntity *entity);

	Player				_player;
	Entities			_entities;
	clock_t				_last_wave;
	clock_t				_game_start;

	static int			_wavesPerSec;
	static int			_wavesDelay;
	static int			_UIHeight;
	static unsigned int	_bestScore;
	static unsigned int	_lastScore;

};

#endif
