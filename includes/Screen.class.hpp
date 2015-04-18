// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:56:54 by gchateau          #+#    #+#             //
//   Updated: 2015/04/18 03:16:32 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCREEN_CLASS_HPP
# define SCREEN_CLASS_HPP

# include <ncurses.h>
# include <iostream>

class IState;

class Screen {

public:
	Screen(void);
	~Screen(void);

	enum state_e
	{
		MENU = 1,
		GAME,
		GAMEOVER
	};

	void			quit(void);
	void			loop(void);
	bool			running(void) const;

	int				getMaxX(void) const;
	int				getMaxY(void) const;
	int				getWidth(void) const;
	int				getHeight(void) const;
	IState *		getState(void) const;
	WINDOW *		getWindow(void) const;

	bool			setState(IState *state);
	bool			setState(state_e state);

	void			clear(void) const;
	void			erase(void) const;
	void			refresh(void) const;
	void			separator(int y) const;
	void			put(int x, int y, unsigned int c) const;
	void			put(int x, int y, std::string s) const;

protected:
	void			init(void);
	void			refreshWinInfos(void);
	void			handle(void);
	void			update(void);
	void			render(void);

private:
	Screen(Screen const & src);
	Screen &	operator=(Screen const & rhs);

	IState *		_buildStateMenu(void) const;
	IState *		_buildStateGame(void) const;
	IState *		_buildStateGameOver(void) const;

	int				_width;
	int				_height;
	bool			_running;

	IState			*_state;
	WINDOW			*_window;

	typedef	IState *	(Screen::*fState_t) (void) const;

	struct StateHook
	{

	public:
		StateHook(void);
		StateHook(state_e key, fState_t callback);
		StateHook(StateHook const & src);
		~StateHook(void);

		StateHook &	operator=(StateHook const & rhs);
		bool		operator==(state_e key);

		state_e			key(void) const;
		fState_t		callback(void) const;

	private:
		state_e			_key;
		fState_t		_callback;

	};

};

#endif
