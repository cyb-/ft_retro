#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 23:11:02 by gchateau          #+#    #+#              #
#    Updated: 2015/04/14 03:13:08 by gchateau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro

CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98
LDFLAGS = -lncurses

FILES = Screen.class Menu.class Game.class GameOver.class Entities.class \
		AEntity.class \
		Enemy Player Rifle Rock main

#******************************************************************************#
#                                     CORE                                     #
#******************************************************************************#

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all
