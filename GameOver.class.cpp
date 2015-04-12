// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameOver.class.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:53:54 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 03:25:24 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameOver.class.hpp"

#include <string>

GameOver::GameOver(void) : _score(0)
{}

GameOver::GameOver(int score) : _score(score)
{}

GameOver::GameOver(GameOver const & src)
{
	if (this != &src)
		*this = src;
}

GameOver::~GameOver(void)
{}

GameOver &		GameOver::operator=(GameOver const & rhs)
{
	(void)rhs;
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
		screen->setState(Screen::GAME);
}

void		GameOver::update(Screen *screen)
{
	(void)screen;
}

void		GameOver::render(Screen *screen)
{
	std::string	msg = "Game Over !!! Press ENTER to start and ESC to exit";
	_score = 1;
	werase(screen->getWindow());
	mvwprintw(screen->getWindow(), screen->getHeight() / 2, (screen->getWidth() - msg.length()) / 2, msg.c_str());
	wrefresh(screen->getWindow());
}
