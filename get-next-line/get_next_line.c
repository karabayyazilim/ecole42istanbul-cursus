/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:09:47 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/02 18:57:56 by akarabay         ###   ########.fr       */
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
	str = (char *)malloc(sizeof(char) * (ft_strlen(create) - index + 1));
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
	read_character = 2000;
	while (!ft_strchr(create, '\n') && read_character != 0)
	{
		read_character = read(fd, buff, BUFFER_SIZE);
		if (read_character == -1)
			return (ft_free(buff));
		buff[read_character] = '\0';
		create = ft_strjoin(create, buff);
	}
	free(buff);
	return (create);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*create;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	create = ft_read_and_create(fd, create);
	if (!create)
		return (0);
	line = ft_get_line(create);
	create = ft_create(create);
	return (line);
}

/*#include <fcntl.h>

int main()
{
    char *s;
    int fd = open("deneme.txt", O_RDONLY | O_CREAT);
    s = get_next_line(fd);
    ft_printf("aaa ---> %s\n", s);
}*/
