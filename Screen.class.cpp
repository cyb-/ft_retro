// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:59:11 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 19:50:50 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Screen.class.hpp"

#include "Menu.class.hpp"
#include "Game.class.hpp"
#include "GameOver.class.hpp"

Screen::Screen(void)
{
	this->init();
}

Screen::Screen(Screen const & src)
{
	*this = src;
}

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
	init_pair('*', COLOR_RED, COLOR_BLACK);
	init_pair('^', COLOR_GREEN, COLOR_BLACK);
	init_pair('V', COLOR_MAGENTA, COLOR_BLACK);
	init_pair('W', COLOR_CYAN, COLOR_BLACK);
	init_pair('O', COLOR_BLUE, COLOR_BLACK);
	init_pair('.', COLOR_YELLOW, COLOR_BLACK);
	init_pair('|', COLOR_WHITE, COLOR_BLACK);
	init_pair(' ', COLOR_WHITE, COLOR_WHITE);
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

void			Screen::setWidth(int width)
{
	this->_width = width;
}

void			Screen::setHeight(int height)
{
	this->_height = height;
}

bool			Screen::setState(Screen::state_e state, int score)
{
	delete this->_state;
	switch (state)
	{
	case GAME:
		this->_state = new Game;
		break;
	case GAMEOVER:
		this->_state = new GameOver(score);
		break;
	default:
		this->_state = new Menu;
	}
	wclear(this->_window);
	this->_state->init(this);
	return (true);
}

bool			Screen::setState(Screen::state_e state)
{
	delete this->_state;
	switch (state)
	{
	case GAME:
		this->_state = new Game;
		break;
	case GAMEOVER:
		this->_state = new GameOver;
		break;
	default:
		this->_state = new Menu;
	}
	wclear(this->_window);
	this->_state->init(this);
	return (true);
}

void			Screen::changeState(IState *state)
{
	if (state)
	{
		delete this->_state;
		this->_state = state;
		state->init(this);
	}
}

// ************************************************************************** //
//                                WIN HELPERS                                 //
// ************************************************************************** //

void			Screen::erase(void) const
{
	werase(this->_window);
}

void			Screen::refresh(void) const
{
	wrefresh(this->_window);
}

void			Screen::put(int x, int y, unsigned int c) const
{
	wattron(this->_window, COLOR_PAIR(c));
	mvwaddch(this->_window, y, x, c);
	wattroff(this->_window, COLOR_PAIR(c));
}

void			Screen::put(int x, int y, std::string s) const
{
	mvwprintw(this->_window, y, x, s.c_str());
}
