// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEntity.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/12 16:38:40 by gchateau          #+#    #+#             //
//   Updated: 2015/04/14 00:28:42 by gchateau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AENTITY_CLASS_HPP
# define AENTITY_CLASS_HPP

# include "Screen.class.hpp"

# include <string>
# include <ctime>

class	AEntity
{

public:
	AEntity(int x, int y, std::string type, char body, int hp, int lives, int points, int vector, int speed);
	AEntity(AEntity const & src);
	virtual ~AEntity(void);

	AEntity &	operator=(AEntity const & rhs);

	int					getX(void) const;
	int					getY(void) const;
	std::string			getType(void) const;
	char				getBody(void) const;
	bool				getCollidable(void) const;
	int					getHP(void) const;
	int					getLives(void) const;
	int					getPoints(void) const;
	int					getVector(void) const;
	int					getSpeed(void) const;

	void				setPosition(int x, int y);
	void				setBody(char body);
	void				setHP(int i);

	void				move(std::string direction);
	void				move(void);
	void				moveUp(Screen *screen);
	void				moveDown(Screen *screen);
	void				moveLeft(Screen *screen);
	void				moveRight(Screen *screen);
	bool				canMove(void);
	bool				collision(AEntity * entity);

	virtual void		looseHP(void);
	virtual void		looseLife(void);
	virtual AEntity *	clone(void) const = 0;
	virtual AEntity *	shoot(void) = 0;

	typedef	void		(AEntity::*fKey_t) (Screen *);

	struct KeyHook
	{

	public:
		KeyHook(void);
		KeyHook(int key, AEntity::fKey_t callback);
		KeyHook(KeyHook const & src);
		~KeyHook(void);

		KeyHook &	operator=(KeyHook const & rhs);
		bool		operator==(int key);

		int			key(void) const;
		fKey_t		callback(void) const;

	private:
		int			_key;
		fKey_t		_callback;

	};

protected:
	int			_PosY;
	int			_PosX;
	char		_Body;
	int			_HP;
	int			_Lives;
	bool		_Collidable;
	std::string	_Type;
	int			_Points;
	int			_vector;
	int			_speed;
	clock_t		_last_move;
	clock_t		_last_shoot;

private:
	AEntity(void);

};

#endif
