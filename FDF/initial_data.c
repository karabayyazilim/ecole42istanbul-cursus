/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:14:50 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/12 01:04:39 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_fdf *data)
{
	data->shift_x = 600;
	data->shift_y = 400;
	data->zoom = 30;
	data->degree = 0.8;
	data->color = 0xffffff;
	data->param_y = 0;
	data->param_x = 0;
	data->param_x1 = 0;
	data->param_y1 = 0;
	data->color_flag = 0;
}
