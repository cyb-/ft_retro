// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IState.interface.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:40:59 by gchateau          #+#    #+#             //
//   Updated: 2015/04/13 00:54:15 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ISTATE_INTERFACE_HPP
# define ISTATE_INTERFACE_HPP

# define KEY_ESC	(27)
# define KEY_SPACE	(' ')

# include "Screen.class.hpp"

class IState {

public:
	virtual ~IState(void) {};
	virtual void		init(Screen *screen) = 0;
	virtual void		handle(Screen *screen) = 0;
	virtual void		update(Screen *screen) = 0;
	virtual void		render(Screen *screen) = 0;

	typedef	void		(IState::*t_fKey)(Screen *);

	struct fKey_s
	{

	public:
		int				key;
		IState::t_fKey	*callback;

	private:
		fKey_s(void);
		fKey_s(fKey_s const & src);
		~fKey_s(void);
		fKey_s &	operator=(fKey_s const & rhs);

	};

};

#endif
