// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:56:54 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 00:38:59 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCREEN_CLASS_HPP
# define SCREEN_CLASS_HPP

# include <ncurses.h>

class IState;

class Screen {

public:
	Screen(void);
	Screen(Screen const & src);
	~Screen(void);

	Screen &	operator=(Screen const & rhs);

	void			init(WINDOW *screen);
	void			quit(void);
	void			changeState(IState *state);

	void			handle(void);
	void			update(void);
	void			render(void);

	bool			running(void) const;

	WINDOW *		getWindow(void) const;

	int				getWidth(void) const;
	int				getHeight(void) const;

	void			setWidth(int width);
	void			setHeight(int height);

private:
	int				_width;
	int				_height;
	bool			_running;

	WINDOW			*_window;
	IState			*_state;

};

#endif
