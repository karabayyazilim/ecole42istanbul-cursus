LIBFT_DIR   =   includes/libft
LIBFT_MAKE  =   Makefile
LIBFT_PATH  =   ./includes/libft/libft.a
MLX_DIR =   minilibx
MLX_MAKE    =   Makefile
MLX_PATH    =   ${MLX_DIR}/libmlx.a

CC  	=   gcc
CFLAGS  =   -Wall -Wextra -Werror
MFLAGS  =   ./minilibx ./minilibx/libmlx.a ./libft/libft.a -framework OpenGL -framework AppKit
NAME    =   fdf
RM  =   rm -rf

all:    $(NAME)

$(NAME): $(OBJS)
		make -C ./libft
		make -C ./minilibx
		gcc -o $(NAME) ./*.c -I $(MFLAGS) $(CFLAGS)

fclean: clean
		${RM} ./libft/*.a
		${RM} ./minilibx/*.a
clean:
		${RM} ./libft/*.o
		${RM} ./libft/*/*.o
		${RM} ./minilibx/*.ox
		${RM} ./src/*.o
		${RM} ${NAME}

re: fclean all

.PHONY: all fclean clean re