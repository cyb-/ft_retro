// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Menu.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:53:54 by gchateau          #+#    #+#             //
//   Updated: 2015/04/11 13:17:31 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Menu.class.hpp"
#include "Game.class.hpp"
#include <string>

// CONSTRUCTORS AND DESTRUCTOR

Menu::Menu(void)
{}

Menu::Menu(Menu const & src)
{
	if (this != &src)
		*this = src;
}

Menu::~Menu(void)
{}

// OPERATORS OVERLOAD

Menu &		Menu::operator=(Menu const & rhs)
{
	(void)rhs;
	return (*this);
}

// ENGINE

void		Menu::init(Screen *screen)
{
	(void)screen;
	clear();
}

void		Menu::handle(Screen *screen)
{
	int			ch = wgetch(screen->getWindow());

	if (ch == KEY_ESC)
		screen->quit();
	else if (ch == KEY_ENTER || ch == 10)
	{
		IState	*st = new Game;
		screen->changeState(st);
	}
}

void		Menu::update(Screen *screen)
{
	std::string	msg = "Press ENTER to start and ESC to exit";

	mvwprintw(screen->getWindow(), screen->getHeight() / 2, (screen->getWidth() - msg.length()) / 2, msg.c_str());
}

void		Menu::draw(Screen *screen)
{
	(void)screen;
	refresh();
}
