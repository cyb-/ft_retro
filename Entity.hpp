/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:25:11 by jzimini           #+#    #+#             */
//   Updated: 2015/04/11 22:28:42 by gchateau         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <string>

class	Entity
{
	public:
		Entity(int x, int y, std::string type, char body, int hp, int lives, int points, int vector, int speed);
		Entity(Entity const & src);
		virtual ~Entity(void);

		int				getX(void) const;
		int				getY(void) const;
		std::string		getType(void) const;
		char			getBody(void) const;
		std::string		getBodyS(void) const;
		bool			getCollidable(void) const;
		int				getHP(void) const;
		int				getLives(void) const;
		int				getPoints(void) const;
		int				getVector(void) const;
		int				getSpeed(void) const;

		void			setPosition(int x, int y);
		void			setBody(char body);
		void			setHP(int i);
		virtual void	looseHP(void);
		virtual void	looseLife(void);
		void			move(std::string direction);
		void			move(void);
		bool	collision(Entity * entity);
		virtual Entity *	clone(void) const = 0;
		virtual Entity *	shoot() = 0;

		Entity &		operator=(Entity const & rhs);

	protected:
		int			_PosY;
		int			_PosX;
		char		_Body;
		std::string	_BodyS;
		int			_HP;
		int			_Lives;
		bool		_Collidable;
		std::string	_Type;
		int			_Points;
		int			_vector;
		int			_speed;
		Entity(void);
};

#endif
