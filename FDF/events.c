/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:14:30 by akarabay          #+#    #+#             */
/*   Updated: 2022/03/22 14:14:30 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_event(t_fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw(data);
}

void	mouse_handler(t_fdf *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 17, close_frame, data);
	mlx_hook(data->win_ptr, 4, 1L << 11, mouse_release, data);
	mlx_hook(data->win_ptr, 5, 1L << 12, mouse_release, data);
}

int	keyboard_handler(int key, t_fdf *data)
{
	if (key == 13)
		data->shift_y += 10;
	else if (key == 1 || key == 0 || key == 2 || key == 13)
		key_shift(key, data);
	else if (key == 124 || key == 123)
		key_degree(key, data);
	else if (key == 8 || key == 9 || key == 17)
		key_color(key, data);
	else if (key == 15)
		init_data(data);
	else if (key == 53)
	{
		free_data(data);
		exit(0);
	}
	handle_event(data);
	return (0);
}
