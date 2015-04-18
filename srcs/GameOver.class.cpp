// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameOver.class.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:53:54 by gchateau          #+#    #+#             //
//   Updated: 2015/04/18 02:20:35 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameOver.class.hpp"

#include <string>

GameOver::GameOver(void)
{}

GameOver::GameOver(GameOver const &)
{}

GameOver::~GameOver(void)
{}

GameOver &		GameOver::operator=(GameOver const &)
{
	return (*this);
}

// ************************************************************************** //
//                                   ENGINE                                   //
// ************************************************************************** //

void		GameOver::init(Screen *screen)
{
	(void)screen;
}

void		GameOver::handle(Screen *screen)
{
	int			ch = wgetch(screen->getWindow());

	if (ch == KEY_ESC)
		screen->quit();
	else if (ch == KEY_ENTER || ch == 10)
		screen->setState(Screen::MENU);
}

void		GameOver::update(Screen *screen)
{
	(void)screen;
}

void		GameOver::render(Screen *screen)
{
	static const char	*asciiArt[] = {
		"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
		"%....................................................................%",
		"%...%%%%....%%%%...%%...%%..%%%%%%....%%%%...%%..%%..%%%%%%..%%%%%...%",
		"%..%%......%%..%%..%%%.%%%..%%.......%%..%%..%%..%%..%%......%%..%%..%",
		"%..%%.%%%..%%%%%%..%%.%.%%..%%%%.....%%..%%..%%..%%..%%%%....%%%%%...%",
		"%..%%..%%..%%..%%..%%...%%..%%.......%%..%%...%%%%...%%......%%..%%..%",
		"%...%%%%...%%..%%..%%...%%..%%%%%%....%%%%.....%%....%%%%%%..%%..%%..%",
		"%....................................................................%",
		"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
	};
	std::string		msg = "Press ENTER for menu or ESC for exit";
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
	screen->put((screen->getWidth() - msg.length()) / 2, posY +  2, msg);
	screen->refresh();
}
