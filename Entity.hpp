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
		Entity(int x, int y, std::string type, char body, int hp, int lives, int points);
		Entity(Entity const & src);
		virtual ~Entity(void);

		int				getX(void) const;
		int				getY(void) const;
		std::string		getType(void) const;
		char			getBody(void) const;
		std::string		getBodyS(void) const;
		bool			getCollidable(void) const;
		Entity *		getNext(void) const;
		Entity *		getPrev(void) const;
		int				getHP(void) const;
		int				getLives(void) const;
		int				getPoints(void) const;

		void			setNext(Entity * elem);
		void			setPrev(Entity * elem);
		void			setPosition(int x, int y);
		void			setBody(char body);
		void			looseHP(void);
		virtual void	looseLife(void);
		void			move(std::string direction);
		virtual void	collision(Entity & target) = 0;
		virtual Entity *	clone(void) const = 0;

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
		Entity(void);

	private:
		Entity		*next;
		Entity		*prev;

};

#endif
