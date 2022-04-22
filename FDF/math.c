/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:15:11 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/02 23:25:02 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	maximum(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	revert_positive(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	isometric(t_fdf *data, int z, int z1)
{
	data->param_x = (data->param_x - data->param_y) * cos(data->degree);
	data->param_y = (data->param_x + data->param_y) * sin(data->degree) - z;
	data->param_x1 = (data->param_x1 - data->param_y1) * cos(data->degree);
	data->param_y1 = (data->param_x1 + data->param_y1) * sin(data->degree) - z1;
}

void	zoom(t_fdf *data)
{
	data->param_x = data->param_x * data->zoom;
	data->param_y = data->param_y * data->zoom;
	data->param_x1 = data->param_x1 * data->zoom;
	data->param_y1 = data->param_y1 * data->zoom;
}

void	shift(t_fdf *data)
{
	data->param_x += data->shift_x;
	data->param_y += data->shift_y;
	data->param_x1 += data->shift_x;
	data->param_y1 += data->shift_y;
}
