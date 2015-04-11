// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:59:11 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 01:10:09 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Screen.class.hpp"
#include "IState.interface.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTOR

Screen::Screen(void) : _width(0), _height(0), _state(0)
{}

Screen::Screen(Screen const & src)
{
	if (this != &src)
		*this = src;
}

Screen::~Screen(void)
{}

// OPERATORS OVERLOAD

Screen &	Screen::operator=(Screen const & rhs)
{
	if (this != &rhs)
	{
		this->_width = rhs.getWidth();
		this->_height = rhs.getHeight();
	}
	return (*this);
}

// ENGINE

void			Screen::init(WINDOW *window)
{
	int				rows;
	int				cols;

	this->_window = window;
	getmaxyx(stdscr, rows, cols);
	this->_width = cols;
	this->_height = rows;
	keypad(this->_window, TRUE);
	nodelay(this->_window, TRUE);
	noecho();
	curs_set(0);
	ESCDELAY = 20;
	clear();
	this->_running = true;
}

void			Screen::quit(void)
{
	this->_running = false;
}

void			Screen::changeState(IState *state)
{
	if (state)
	{
		delete this->_state;
		std::cout << this->_state << std::endl;
		this->_state = state;
		state->init(this);
	}
}

bool			Screen::running(void) const
{
	return (this->_running);
}

// LOOPS

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

// GETTERS

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

// SETTERS

void			Screen::setWidth(int width)
{
	this->_width = width;
}

void			Screen::setHeight(int height)
{
	this->_height = height;
}
