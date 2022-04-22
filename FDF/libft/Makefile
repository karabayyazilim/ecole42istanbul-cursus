SRCS			=  $(wildcard ./*c)
SRCSPF			=  $(wildcard ./*/*c)

OBJS			= $(SRCS:.c=.o)
OBJSPF			= $(SRCSPF:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I. -g

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS) $(OBJSPF)
				ar rcs $(NAME) $(OBJS) $(OBJSPF)

clean:
				$(RM) $(OBJS) $(OBJSPF)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:			
				@norminette *.[ch] | grep ': OK!' -v ; echo "" 1>/dev/null

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(OBJSPF)

.PHONY:			all clean fclean re bonus norm