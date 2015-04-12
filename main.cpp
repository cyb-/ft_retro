// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 19:11:32 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 03:29:04 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Screen.class.hpp"

#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Rifle.hpp"
#include "Rock.hpp"

#include <iostream>

int		main(void)
{
	{
		Screen		screen;

		std::srand(std::time(0));
		screen.loop();
	}

	// {
	// 	Player	p1;
	// 	Player  p2(p1);
	// 	Rifle	rifle(0, 0, p1);

	// 	Rock	rock(5, 7);
	// 	Enemy	*enemy = new Enemy(5, 0);

	// 	std::cout << p1.getType() << std::endl;
	// 	std::cout << p2.getType() << std::endl;
	// 	std::cout << enemy->getType() << std::endl;
	// 	rock.collision(rifle);
	// 	std::cout << "p1 score: " << p1.getScore() << std::endl;
	// 	std::cout << rifle.getLives() << " rifle life" << std::endl;
	// 	Entity *r2 = p2.shoot();
	// 	std::cout << p2.getLives() << " p2 life " <<std::endl;
	// 	enemy->collision(p1);
	// 	std::cout << p1.getHP() << " p1 hp" << std::endl;
	// 	std::cout << p1.getLives() << " p1 life" << std::endl;
	// 	std::cout << enemy->getHP() << " enemy hp" << std::endl;
	// 	r2->collision(*enemy);
	// 	std::cout << enemy->getHP() << " enemy hp" << std::endl;
	// 	std::cout << "p1 score: " << p1.getScore() << std::endl;
	// 	delete enemy;
	// }
	return (0);
}
