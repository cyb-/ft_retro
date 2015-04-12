// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameOver.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:52:51 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 00:13:43 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GameOver_CLASS_HPP
# define GameOver_CLASS_HPP

# include "IState.interface.hpp"

class GameOver : public IState {

public:
	GameOver(void);
	GameOver(int score);
	GameOver(GameOver const & src);
	virtual ~GameOver(void);

	GameOver &		operator=(GameOver const & rhs);

	void		init(Screen *screen);
	void		handle(Screen *screen);
	void		update(Screen *screen);
	void		render(Screen *screen);

private:
	int			_score;

};

#endif
