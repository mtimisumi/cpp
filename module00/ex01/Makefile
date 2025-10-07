# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: winnitytrinnity <winnitytrinnity@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 15:54:59 by mmisumi           #+#    #+#              #
#    Updated: 2025/10/07 22:22:24 by winnitytrin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++

FLAGS = -std=c++11 -Wall -Wextra -Werror -Iincludes

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