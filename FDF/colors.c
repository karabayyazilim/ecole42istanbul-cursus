/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:14:16 by akarabay          #+#    #+#             */
/*   Updated: 2022/03/22 14:14:16 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(t_fdf *data, int z, int z1, int flag)
{
	if ((z1 || z) && flag == 1)
		data->color = 0x4E4AD5;
	else if ((z1 || z) && !flag)
		data->color = 0xDEC039;
	else if ((z1 || z) && flag == 2)
		data->color = 0xFFFFFF;
	else if (!(z || z1) && flag == 2)
		data->color = 0xE30A17;
	else if (flag != 2)
		data->color = 0xFFFFFF;
}
