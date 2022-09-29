NAME = account

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS=.cpp:.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) -o $(NAME) $(CFLAGS)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)


re:	fclean $(NAME)

