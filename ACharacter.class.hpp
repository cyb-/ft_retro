// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ACharacter.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/12 16:46:14 by gchateau          #+#    #+#             //
//   Updated: 2015/04/12 16:46:15 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ACHARACTER_CLASS_HPP
# define ACHARACTER_CLASS_HPP

# include "AEntity.class.hpp"

class	ACharacter : public AEntity
{

public:
	ACharacter(int x,int y, std::string type, char body, int hp, int lives, int Points, int vector, int speed);
	ACharacter(ACharacter const & src);
	virtual ~ACharacter(void);

	ACharacter &		operator=(ACharacter const & rhs);

	AEntity *			shoot(void) ;
	virtual AEntity *	clone(void) const = 0;

private:
	ACharacter(void);

	static int	_shootDelay;

};

#endif
