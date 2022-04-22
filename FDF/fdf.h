/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:25:24 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/02 23:25:27 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	param_x;
	float	param_y;
	float	param_x1;
	float	param_y1;
	int		width;
	int		height;
	float	zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	double	degree;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color_flag;
	int		**z_matrix;
}			t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	bresenham(t_fdf *data);
void	draw(t_fdf *data);
int		keyboard_handler(int key, t_fdf *data);
void	mouse_handler(t_fdf *data);
float	maximum(float a, float b);
float	revert_positive(float num);
void	isometric(t_fdf *data, int z, int z1);
void	shift(t_fdf *data);
void	zoom(t_fdf *data);
void	set_coordinates(t_fdf *data, int x, int y, int flag);
void	color(t_fdf *data, int z, int z1, int flag);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	key_zoom(int key, t_fdf *data);
void	key_shift(int key, t_fdf *data);
void	key_degree(int key, t_fdf *data);
void	key_color(int key, t_fdf *data);
int		close_frame(t_fdf *data);
void	free_data(t_fdf *data);
int		mouse_release(int key, int x, int y, t_fdf *data);
void	init_data(t_fdf *data);
void	error_permission(int fd, char *file_name, t_fdf *data);
void	error_input(void);
void	data_error_handler(t_fdf *data);
#endif