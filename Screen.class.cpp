// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:59:11 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 05:22:10 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Screen.class.hpp"

#include "Menu.class.hpp"
#include "Game.class.hpp"

#include <unistd.h> // For usleep()
#include <ctime>

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
	clock_t			cStart, cEnd;

	while (this->running())
	{
		cStart = std::clock();
		this->refreshWinInfos();
		this->handle();
		this->update();
		this->render();
		cEnd = std::clock();
		if ((cEnd - cStart) / CLOCKS_PER_SEC < (CLOCKS_PER_SEC / FPS))
			usleep((CLOCKS_PER_SEC / FPS) - ((cEnd - cStart) / CLOCKS_PER_SEC));
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

bool			Screen::setState(Screen::state_e state)
{
	delete this->_state;
	switch (state)
	{
	case GAME:
		this->_state = new Game;
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
