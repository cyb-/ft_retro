// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEntity.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/12 16:38:40 by gchateau          #+#    #+#             //
//   Updated: 2015/04/20 23:54:55 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AENTITY_CLASS_HPP
# define AENTITY_CLASS_HPP

# include <string>
# include <ctime>

class	AEntity
{

public:
	AEntity(int x, int y, int vector, int speed, int cHP, int mHP, int damages, int lives, int points, bool collidable);
	AEntity(AEntity const & src);
	virtual ~AEntity(void);

	AEntity &	operator=(AEntity const & rhs);

	int					getX(void) const;
	int					getY(void) const;
	int					getVector(void) const;
	int					getSpeed(void) const;
	int					getCHP(void) const;
	int					getMHP(void) const;
	int					getDamages(void) const;
	int					getLives(void) const;
	int					getPoints(void) const;
	bool				getCollidable(void) const;

	void				setPosition(int x, int y);
	void				takeDamages(int damages);

	void				move(void);
	bool				canMove(void) const;
	bool				killed(void) const;
	bool				dead(void) const;
	bool				collision(AEntity * entity);

	virtual int			getBody(void) const = 0;
	virtual AEntity *	clone(void) const = 0;
	virtual AEntity *	shoot(void) = 0;
	virtual void		die(void);

protected:
	int					_posX;
	int					_posY;
	int					_vector;
	int					_speed;
	int					_cHP;
	int					_mHP;
	int					_damages;
	int					_lives;
	int					_points;
	bool				_collidable;
	clock_t				_last_move;
	clock_t				_last_shoot;

private:
	AEntity(void);

};

#endif
