/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:15:26 by akarabay          #+#    #+#             */
/*   Updated: 2022/03/22 14:15:26 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		error_permission(fd, file_name, data);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name, t_fdf *data)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		error_permission(fd, file_name, data);
	line = get_next_line(fd);
	if (line == NULL)
		error_input();
	width = len_word(line, ' ');
	free(line);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	data->height = get_height(file_name, data);
	data->width = get_width(file_name, data);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	while (i <= data->height)
	{
		data->z_matrix[i] = (int *) malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || ft_strncmp(line, "", 1) == 0)
			break ;
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
}
