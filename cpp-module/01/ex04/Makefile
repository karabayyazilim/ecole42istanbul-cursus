NAME = filereplace
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

CC = g++
CFLAGS = -Wall -Wextra -Werror --std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

