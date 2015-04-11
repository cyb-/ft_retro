// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Menu.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:52:51 by gchateau          #+#    #+#             //
//   Updated: 2015/04/11 13:03:12 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MENU_CLASS_HPP
# define MENU_CLASS_HPP

# include "IState.interface.hpp"

class Menu : public IState {

public:
	Menu(void);
	Menu(Menu const & src);
	virtual ~Menu(void);

	Menu &		operator=(Menu const & rhs);

	void		init(Screen *screen);
	void		handle(Screen *screen);
	void		update(Screen *screen);
	void		draw(Screen *screen);

};

#endif
