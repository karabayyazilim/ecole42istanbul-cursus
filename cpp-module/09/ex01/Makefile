NAME = RPN
SRCS = main.cpp RPN.cpp
OBJS= $(SRCS:.cpp=.o)
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
CC= c++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) $(CPPFLAGS) -o $(NAME)

clean: 
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY : all clean fclean re