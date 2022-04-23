# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 03:06:01 by akarabay          #+#    #+#              #
#    Updated: 2022/04/23 16:15:46 by akarabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c

OBJ		= $(SRC:.c=.o)

NAME	= libftprintf.a

CC		= @gcc

CFLAGS	= -Wall -Wextra -Werror -I.

RM		= @rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
			@ar rcs $(NAME) $(OBJ)

clean:	
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)
