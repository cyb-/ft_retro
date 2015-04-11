// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IState.interface.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:40:59 by gchateau          #+#    #+#             //
//   Updated: 2015/04/11 13:02:26 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ISTATE_INTERFACE_HPP
# define ISTATE_INTERFACE_HPP

# define KEY_ESC 27

# include "Screen.class.hpp"

class IState {

public:
	virtual ~IState(void) {};
	virtual void		init(Screen *screen) = 0;
	virtual void		handle(Screen *screen) = 0;
	virtual void		update(Screen *screen) = 0;
	virtual void		draw(Screen *screen) = 0;

};

#endif
