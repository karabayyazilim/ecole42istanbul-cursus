/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:13:44 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/02 23:15:04 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(t_fdf *data)
{
	int	index;

	index = 0;
	while (index < data->height)
	{
		free(data->z_matrix[index++]);
	}
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->z_matrix);
	free(data);
}

void	error_permission(int fd, char *file_name, t_fdf *data)
{
	if (fd == -1)
	{
		ft_printf("Something went wrong while trying to open %s.", file_name);
		ft_printf("\nPlease, check file and try again.");
		close(fd);
		free(data);
		exit(1);
	}
}

void	error_input(void)
{
	ft_printf("Invalid input!");
	ft_printf("\nPlease, check file and try again.");
	exit(1);
}

void	data_error_handler(t_fdf *data)
{
	if (!data->z_matrix)
		error_input();
}
