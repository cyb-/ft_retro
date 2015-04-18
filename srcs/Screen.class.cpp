// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:59:11 by gchateau          #+#    #+#             //
//   Updated: 2015/04/18 03:28:48 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Screen.class.hpp"

#include "Menu.class.hpp"
#include "Game.class.hpp"
#include "GameOver.class.hpp"

Screen::Screen(void) : _width(0), _height(0), _running(false), _state(0), _window(0)
{
	this->init();
}

Screen::Screen(Screen const & src) : _width(src.getWidth()),
									 _height(src.getHeight()),
									 _running(src.running()),
									 _state(src.getState()),
									 _window(src.getWindow())
{}

Screen::~Screen(void)
{
	delete this->_state;
	endwin();
}

Screen &	Screen::operator=(Screen const & rhs)
{
	if (this != &rhs)
	{
		this->_window = rhs.getWindow();
		this->_width = rhs.getWidth();
		this->_height = rhs.getHeight();
		this->_running = rhs.running();
	}
	return (*this);
}

// ************************************************************************** //
//                                   ENGINE                                   //
// ************************************************************************** //

void			Screen::init(void)
{
	this->_window = initscr();
	start_color();
	wbkgd(this->_window, COLOR_BLACK);
	init_pair(' ', COLOR_WHITE, COLOR_WHITE);
	init_pair('*', COLOR_RED, COLOR_BLACK);
	init_pair('.', COLOR_YELLOW, COLOR_BLACK);
	init_pair('V', COLOR_MAGENTA, COLOR_BLACK);
	init_pair('^', COLOR_GREEN, COLOR_BLACK);
	init_pair('O', COLOR_BLUE, COLOR_BLACK);
	init_pair('W', COLOR_CYAN, COLOR_BLACK);
	init_pair('|', COLOR_WHITE, COLOR_BLACK);
	keypad(this->_window, TRUE);
	nodelay(this->_window, TRUE);
	noecho();
	curs_set(0);
	ESCDELAY = 20;
	wclear(this->_window);
	getmaxyx(this->_window, this->_height, this->_width);
	this->_running = true;
	this->setState(MENU);
}

void			Screen::refreshWinInfos(void)
{
	getmaxyx(this->_window, this->_height, this->_width);
}

void			Screen::quit(void)
{
	this->_running = false;
}

bool			Screen::running(void) const
{
	return (this->_running);
}

// ************************************************************************** //
//                                   LOOPS                                    //
// ************************************************************************** //

void			Screen::loop(void)
{
	while (this->running())
	{
		this->refreshWinInfos();
		this->handle();
		this->update();
		this->render();
	}
}

void			Screen::handle(void)
{
	this->_state->handle(this);
}

void			Screen::update(void)
{
	this->_state->update(this);
}

void			Screen::render(void)
{
	this->_state->render(this);
}

// ************************************************************************** //
//                                  GETTERS                                   //
// ************************************************************************** //

IState *		Screen::getState(void) const
{
	return (this->_state);
}

WINDOW *		Screen::getWindow(void) const
{
	return (this->_window);
}

int				Screen::getWidth(void) const
{
	return (this->_width);
}

int				Screen::getHeight(void) const
{
	return (this->_height);
}

int				Screen::getMaxX(void) const
{
	return (this->_width <= 0 ? 0 : this->_width - 1);
}

int				Screen::getMaxY(void) const
{
	return (this->_height <= 0 ? 0 : this->_height - 1);
}

// ************************************************************************** //
//                                  MUTATORS                                  //
// ************************************************************************** //

bool			Screen::setState(IState *state)
{
	if (state != 0)
	{
		delete this->_state;
		this->_state = state;
		this->clear();
		state->init(this);
		return (true);
	}
	return (false);
}

bool			Screen::setState(Screen::state_e state)
{
	unsigned int	i = 0;
	StateHook		states[] = {
		StateHook(MENU, &Screen::_buildStateMenu),
		StateHook(GAME, &Screen::_buildStateGame),
		StateHook(GAMEOVER, &Screen::_buildStateGameOver)
	};

	while (i < (sizeof(states) / sizeof(states[0])))
	{
		if (states[i] == state)
			return (this->setState((this->*states[i].callback())()));
		i++;
	}
	return (false);
}

// ************************************************************************** //
//                               STATE HELPERS                                //
// ************************************************************************** //

IState *		Screen::_buildStateMenu(void) const
{
	return (new Menu);
}

IState *		Screen::_buildStateGame(void) const
{
	return (new Game);
}

IState *		Screen::_buildStateGameOver(void) const
{
	return (new GameOver);
}

// ************************************************************************** //
//                                WIN HELPERS                                 //
// ************************************************************************** //

void			Screen::clear(void) const
{
	wclear(this->_window);
}

void			Screen::erase(void) const
{
	werase(this->_window);
}

void			Screen::refresh(void) const
{
	wrefresh(this->_window);
}

void			Screen::separator(int y) const
{
	for (int x = 0; x < this->_width; x++)
		mvwaddch(this->_window, y, x, ' ' | A_REVERSE);
}

void			Screen::put(int x, int y, unsigned int c) const
{
	wattron(this->_window, COLOR_PAIR((char)c));
	mvwaddch(this->_window, y, x, c);
	wattroff(this->_window, COLOR_PAIR((char)c));
}

void			Screen::put(int x, int y, std::string s) const
{
	mvwprintw(this->_window, y, x, s.c_str());
}

// ************************************************************************** //
//                             Screen::StateHook                              //
// ************************************************************************** //

Screen::StateHook::StateHook(void) : _key(Screen::MENU), _callback(0)
{}

Screen::StateHook::StateHook(Screen::state_e key, Screen::fState_t callback) : _key(key), _callback(callback)
{}

Screen::StateHook::StateHook(Screen::StateHook const & src) : _key(src.key()), _callback(src.callback())
{}

Screen::StateHook::~StateHook(void)
{}

Screen::StateHook &	Screen::StateHook::operator=(Screen::StateHook const & rhs)
{
	if (this != &rhs)
	{
		this->_key = rhs.key();
		this->_callback = rhs.callback();
	}
	return (*this);
}

bool				Screen::StateHook::operator==(Screen::state_e key)
{
	return (this->_key == key);
}

Screen::state_e		Screen::StateHook::key(void) const
{
	return (this->_key);
}

Screen::fState_t	Screen::StateHook::callback(void) const
{
	return (this->_callback);
}
