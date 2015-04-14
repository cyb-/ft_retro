#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 23:11:02 by gchateau          #+#    #+#              #
#    Updated: 2015/04/14 03:20:46 by gchateau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro

SRC_PATH = srcs/
INC_PATH = includes/

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
LFLAGS = -I $(INC_PATH)
LDFLAGS = -lncurses

FILES = Screen.class Menu.class Game.class GameOver.class Entities.class \
		AEntity.class Enemy Player Rifle Rock main

#******************************************************************************#
#                                     CORE                                     #
#******************************************************************************#

SRCS = $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(FILES)))
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all
