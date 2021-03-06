# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dezzeddi <dezzeddi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 19:06:22 by ikozlov           #+#    #+#              #
#    Updated: 2019/07/28 17:54:11 by dezzeddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC_DIR = srcs/
OBJ_DIR = objs/

SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.cpp))
OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIB = -lncurses
LIB +=  -framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML/Frameworks
INC = -I includes/ -I ./SFML/include

CXX = clang++
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) $(INC) $(LIB) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re $(NAME)