/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:28:05 by akarabay          #+#    #+#             */
/*   Updated: 2022/03/07 18:42:27 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[index])
	{
		if (str[index] == (char)c)
			return ((char *)&str[index]);
		index++;
	}
	return (NULL);
}

/*
int main()
{
    char a[] = "hello";
    printf("%s", ft_strchr(a, 'l'));
}*/
