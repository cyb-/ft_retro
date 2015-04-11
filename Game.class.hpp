// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:47:13 by gchateau          #+#    #+#             //
//   Updated: 2015/04/11 19:03:40 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# define GAME_FPS 20

# include "IState.interface.hpp"
# include "Player.hpp"
# include "Entities.hpp"

class Game : public IState {

public:
	Game(void);
	Game(Game const & src);
	~Game(void);

	Game &	operator=(Game const & rhs);

	void				init(Screen *screen);
	void				handle(Screen *screen);
	void				update(Screen *screen);
	void				draw(Screen *screen);

	unsigned int		getLoops(void) const;
	Player const &		getPlayer(void) const;
	Entities const &	getEntities(void) const;

private:
	void				_generateWave(Screen *screen);

	int					_cStart;
	int					_cEnd;
	Player				_player;
	Entities			_entities;
	unsigned int		_loops;

};

#endif
