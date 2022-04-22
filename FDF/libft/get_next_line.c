/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:09:47 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/02 23:08:44 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *create)
{
	int		index;
	char	*str;

	index = 0;
	if (!create[index])
		return (NULL);
	while (create[index] && create[index] != '\n')
		index++;
	str = (char *)malloc(sizeof(char) * (index + 2));
	if (!str)
		return (NULL);
	index = -1;
	while (create[++index] && create[index] != '\n')
		str[index] = create[index];
	if (create[index] == '\n')
	{
		str[index] = create[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_create(char *create)
{
	int		index;
	int		str_index;
	char	*str;

	index = 0;
	while (create[index] && create[index] != '\n')
		index++;
	if (!create[index])
		return (ft_free(create));
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(create) - index + 1));
	if (!str)
		return (NULL);
	index++;
	str_index = 0;
	while (create[index])
		str[str_index++] = create[index++];
	str[str_index] = '\0';
	free(create);
	return (str);
}

char	*ft_read_and_create(int fd, char *create)
{
	char	*buff;
	int		read_character;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_character = 1;
	while (!ft_strchr_gnl(create, '\n') && read_character != 0)
	{
		read_character = read(fd, buff, BUFFER_SIZE);
		if (read_character == -1)
			return (ft_free(buff));
		buff[read_character] = '\0';
		create = ft_strjoin_gnl(create, buff);
	}
	free(buff);
	return (create);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*create[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	create[fd] = ft_read_and_create(fd, create[fd]);
	if (!create[fd])
		return (0);
	line = ft_get_line(create[fd]);
	create[fd] = ft_create(create[fd]);
	return (line);
}
