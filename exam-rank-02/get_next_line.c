/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:02:04 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/25 11:44:16 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void	*myfree(void *f)
{
	free(f);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*ret	= (char *)malloc(sizeof(char) * 9999);
	char	buff	= 0;
	int		j		= 0;
	int		i		= 1;
	while (i > 0)
	{
		i = read(fd, &buff, 1);
		if (i <= 0)
			break ;
		ret[j++] = buff;
		if (buff == '\n')
			break ;
	}
	ret[j] = 0;
	if (!*ret)
		return (myfree(ret));
	return (ret);
}

/*static int ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

static int ft_strchr(char *str, int c)
{
	int index;

	if (!str)
		return (0);
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == (char)c)
			return (1);
		index++;
	}
	return (0);
}

static char *join(char *s1, char *s2)
{
	int index;
	int sindex;
	int s1len;
	int s2len;
	char *str;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	index = -1;
	str = malloc(s1len + s2len + 1);
	if (!str)
		return (0);
	while (s1[++index])
		str[index] = s1[index];
	sindex = 0;
	while (s2[sindex])
	{
		str[index] = s2[sindex];
		index++;
		sindex++;
	}
	str[index] = '\0';
	free(s1);
	return (str);
}

static char *get_line(char *create)
{
	int index;
	char *str;

	index = 0;
	if (!create[index])
		return (0);
	while (create[index] && create[index] != '\n')
		index++;
	str = malloc(index + 2);
	if (!str)
		return (0);
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

static char *ft_create(char *create)
{
	int index;
	int sindex;
	char *str;

	index = 0;
	sindex = 0;
	while (create[index] && create[index] != '\n')
		index++;
	if (!create[index])
	{
		free(create);
		return (0);
	}
	str = malloc(ft_strlen(create) - index + 1);
	if (!str)
		return (0);
	index++;
	while (create[index])
		str[sindex++] = create[index++];
	str[sindex] = '\0';
	free(create);
	return (str);
}

static char *ft_read_create(int fd, char *create)
{
	int read_char;
	char *buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	read_char = 100;
	while (!ft_strchr(create, '\n') && read_char != 0)
	{
		read_char = read(fd, buff, BUFFER_SIZE);
		if (read_char == -1)
		{
			free(buff);
			return (0);
		}
		buff[read_char] = '\0';
		create = join(create, buff);
	}
	free(buff);
	return (create);
}

char *get_next_line(int fd)
{
	static char *create;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	create = ft_read_create(fd, create);
	if (!create)
		return (0);
	line = get_line(create);
	create = ft_create(create);
	return (line);
}*/



#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("union.c", O_RDONLY);

	printf("aaa ---> %s\n", get_next_line(fd));
}
