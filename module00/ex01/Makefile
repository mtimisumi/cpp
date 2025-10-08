# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 15:54:59 by mmisumi           #+#    #+#              #
#    Updated: 2025/10/08 13:28:41 by mmisumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++

#it is not mandatory for codam students to follow the c++11 rules
FLAGS = -std=c++17 -Wall -Wextra -Werror -Iincludes

SRCS	:= src/Main.cpp src/PhoneBook.cpp src/Contact.cpp
OBJS	:= $(patsubst src/%.cpp, .obj/%.o, $(SRCS))

all: $(NAME)

.obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "Compiled successfully!"

clean:
	@rm -rf .obj
	@echo "Cleanup complete!"

fclean: clean
	@rm -rf $(NAME)
	@echo "Executable removed!"

re: fclean all

.PHONY: all clean fclean re