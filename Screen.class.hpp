// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:56:54 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 02:59:21 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCREEN_CLASS_HPP
# define SCREEN_CLASS_HPP

# define FPS	20

# include <ncurses.h>

class IState;

class Screen {

public:
	Screen(void);
	Screen(Screen const & src);
	~Screen(void);

	enum state_e
	{
		MENU = 1,
		GAME
	};

	Screen &	operator=(Screen const & rhs);

	void			quit(void);
	void			changeState(IState *state);

	void			loop(void);
	bool			running(void) const;

	int				getWidth(void) const;
	int				getHeight(void) const;
	IState *		getState(void) const;
	WINDOW *		getWindow(void) const;

	void			setWidth(int width);
	void			setHeight(int height);
	bool			setState(state_e state);

protected:
	void			init(void);
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
