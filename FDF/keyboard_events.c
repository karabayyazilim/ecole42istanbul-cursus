/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:14:58 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/02 23:13:17 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_shift(int key, t_fdf *data)
{
	if (key == 13)
		data->shift_y += 10;
	else if (key == 1)
		data->shift_y -= 10;
	else if (key == 0)
		data->shift_x += 10;
	else if (key == 2)
		data->shift_x -= 10;
}

void	key_degree(int key, t_fdf *data)
{
	if (key == 124)
		data->degree += 0.1;
	else if (key == 123)
		data->degree -= 0.1;
}

void	key_color(int key, t_fdf *data)
{
	if (key == 8)
		data->color_flag = 1;
	else if (key == 9)
		data->color_flag = 0;
	else if (key == 17)
		data->color_flag = 2;
}
