NAME = scav

SRC = main.cpp ScavTrap.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

re: clean all

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re
