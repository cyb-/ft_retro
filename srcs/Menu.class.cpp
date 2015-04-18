// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Menu.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:53:54 by gchateau          #+#    #+#             //
//   Updated: 2015/04/18 02:21:02 by gchateau         ###   ########.fr       //
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
	screen->erase();
	static const char	*asciiArt[] = {
		"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
		"%...............................................................%",
		"%..%%%%%%..%%%%%%.......%%%%%...%%%%%%..%%%%%%..%%%%%....%%%%...%",
		"%..%%........%%.........%%..%%..%%........%%....%%..%%..%%..%%..%",
		"%..%%%%......%%.........%%%%%...%%%%......%%....%%%%%...%%..%%..%",
		"%..%%........%%.........%%..%%..%%........%%....%%..%%..%%..%%..%",
		"%..%%........%%..%%%%%..%%..%%..%%%%%%....%%....%%..%%...%%%%...%",
		"%...............................................................%",
		"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
	};
	std::string		msg = "Press ENTER to start or ESC to exit";
	unsigned int	x, y = 0;
	unsigned int	asciiHeight, asciiWidth;
	int				posX, posY;

	asciiHeight = sizeof(asciiArt) / sizeof(asciiArt[0]);
	asciiWidth = std::strlen(asciiArt[0]);
	screen->erase();
	while (y < asciiHeight)
	{
		posY = y + ((screen->getHeight() - asciiHeight) / 2);
		x = 0;
		while (x < asciiWidth)
		{
			posX = x + ((screen->getWidth() - asciiWidth) / 2);
			if (asciiArt[y][x] == '%')
				screen->put(posX, posY, ' ' | A_REVERSE);
			x++;
		}
		y++;
	}
	screen->put((screen->getWidth() - msg.length()) / 2, posY + 2, msg);
	screen->refresh();
}
