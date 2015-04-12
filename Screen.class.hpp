// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:56:54 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 18:18:14 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCREEN_CLASS_HPP
# define SCREEN_CLASS_HPP

# define FPS	20

# include <ncurses.h>
# include <iostream>

class IState;

class Screen {

public:
	Screen(void);
	Screen(Screen const & src);
	~Screen(void);

	enum state_e
	{
		MENU = 1,
		GAME,
		GAMEOVER
	};

	Screen &	operator=(Screen const & rhs);

	void			quit(void);
	void			changeState(IState *state);

	void			loop(void);
	bool			running(void) const;

	int				getMaxX(void) const;
	int				getMaxY(void) const;
	int				getWidth(void) const;
	int				getHeight(void) const;
	IState *		getState(void) const;
	WINDOW *		getWindow(void) const;

	void			setWidth(int width);
	void			setHeight(int height);
	bool			setState(state_e state);
	bool			setState(state_e state, int score);

	void			erase(void) const;
	void			refresh(void) const;
	void			put(int x, int y, unsigned int c) const;
	void			put(int x, int y, std::string s) const;

protected:
	void			init(void);
	void			refreshWinInfos(void);
	void			handle(void);
	void			update(void);
	void			render(void);

private:
	int				_width;
	int				_height;
	bool			_running;

	IState			*_state;
	WINDOW			*_window;

};

#endif
