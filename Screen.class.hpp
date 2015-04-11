// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:56:54 by gchateau          #+#    #+#             //
//   Updated: 2015/04/11 13:00:39 by gchateau         ###   ########.fr       //
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
	void			draw(void);

	bool			running(void) const;

	WINDOW *		getWindow(void) const;

	unsigned int	getWidth(void) const;
	unsigned int	getHeight(void) const;

	void			setWidth(unsigned int width);
	void			setHeight(unsigned int height);

private:

	WINDOW					*_window;

	unsigned int			_width;
	unsigned int			_height;
	bool					_running;

	IState					*_state;

};

#endif
