#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 23:11:02 by gchateau          #+#    #+#              #
#    Updated: 2015/04/11 22:45:41 by gchateau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro

CC = clang++
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lncurses

FILES = Screen.class Menu.class Game.class Entities.class Entity Character \
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

fclean: clean
	rm -f $(NAME)

re: fclean all
