NAME = megaphone

CC = c++

# it is not mandatory for codam students to follow the c++98 rules
FLAGS = -std=c++17 -Wall -Wextra -Werror

SRCS	:= src/megaphone.cpp
OBJS	:= $(patsubst src/%.cpp, .obj/%.o, $(SRCS))

all: $(NAME)

.obj/%.o: src/%.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm -rf .obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re