SRCS	= ft_printf.c ft_printf_utils.c ft_putnbr.c
OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror


all :  ${NAME}

$(NAME) : ${OBJS}
	ar rc $(NAME) $(OBJS)

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

norm :
	norminette *.[ch]

re : fclean all