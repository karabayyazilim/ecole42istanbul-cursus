/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:04:58 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/02 23:08:17 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *str, int c)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen_gnl(str)]);
	while (str[index])
	{
		if (str[index] == (char)c)
			return ((char *)&str[index]);
		index++;
	}
	return (NULL);
}

size_t	ft_strlcpy_gnl(char	*dst, const char *src, size_t	dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen_gnl(src);
	if (!dstsize)
		return (srcsize);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len_s1 = (ft_strlen_gnl((char *)s1));
	len_s2 = (ft_strlen_gnl((char *)s2));
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy_gnl(res, s1, len_s1 + 1);
	ft_strlcpy_gnl(&res[len_s1], s2, len_s2 + 1);
	free(s1);
	return (res);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

void	*ft_free(void *str)
{
	free(str);
	return (NULL);
}
