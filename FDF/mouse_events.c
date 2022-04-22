/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:15:17 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/02 23:55:17 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_zoom(int key, t_fdf *data)
{
	if (key == 4)
		data->zoom += 1;
	else if (key == 5)
		data->zoom -= 1;
}

int	mouse_release(int key, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	if (key == 4 || key == 5)
		key_zoom(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw(data);
	return (0);
}

int	close_frame(t_fdf *data)
{
	free_data(data);
	exit(0);
}
