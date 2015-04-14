// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 19:11:32 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 20:04:53 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Screen.class.hpp"

#include <iostream>

int		main(void)
{
	Screen		screen;

	std::srand(std::time(0));
	screen.loop();
	return (0);
}
