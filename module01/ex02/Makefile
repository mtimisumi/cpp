NAME = brain

CC = c++

# it is not mandatory for codam students to follow the c++98 rules
FLAGS = -Wall -Wextra -Werror

SRCS	:= main.cpp
OBJS	:= $(patsubst %.cpp, .obj/%.o, $(SRCS))

all: $(NAME)

.obj/%.o: %.cpp
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