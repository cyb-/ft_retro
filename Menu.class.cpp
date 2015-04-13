// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Menu.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:53:54 by gchateau          #+#    #+#             //
//   Updated: 2015/04/13 23:24:41 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Menu.class.hpp"

#include <string>

Menu::Menu(void)
{}

Menu::Menu(Menu const & src)
{
	if (this != &src)
		*this = src;
}

Menu::~Menu(void)
{}

Menu &		Menu::operator=(Menu const & rhs)
{
	(void)rhs;
	return (*this);
}

// ************************************************************************** //
//                                   ENGINE                                   //
// ************************************************************************** //

void		Menu::init(Screen *screen)
{
	(void)screen;
}

void		Menu::handle(Screen *screen)
{
	int			ch = wgetch(screen->getWindow());

	if (ch == KEY_ESC)
		screen->quit();
	else if (ch == KEY_ENTER || ch == 10)
		screen->setState(Screen::GAME);
}

void		Menu::update(Screen *screen)
{
	(void)screen;
}

void		Menu::render(Screen *screen)
{
	std::string	msg = "Press ENTER to start and ESC to exit";

	screen->erase();
	screen->put((screen->getWidth() - msg.length()) / 2, screen->getHeight() / 2, msg);
	screen->refresh();
}
