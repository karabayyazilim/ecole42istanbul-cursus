/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:15:36 by akarabay          #+#    #+#             */
/*   Updated: 2022/03/22 14:15:36 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_coordinates(t_fdf *data, int x, int y, int flag)
{
	data->param_x = x;
	data->param_y = y;
	if (flag == 0)
	{
		data->param_y1 = y;
		data->param_x1 = x + 1;
	}
	else
	{
		data->param_y1 = y + 1;
		data->param_x1 = x;
	}
}
