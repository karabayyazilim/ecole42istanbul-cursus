NAME	=	philo
SRCS	=	philosophers.c	philo_tools.c	philo_utils.c	philo_behaviours.c	philo_check.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc #-fsanitize=thread -g
RM		=	rm -rf
CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)
			

re:	fclean $(NAME)

norm:
	norminette *.[ch]

.PHONY:	all clean fclean re
