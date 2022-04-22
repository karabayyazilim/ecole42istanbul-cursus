/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:28:05 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/13 12:01:08 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == (char)c)
			return ((char *)(str + index));
		index++;
	}
	if (str[index] == (char)c)
		return ((char *)(str + index));
	return (NULL);
}

/*
int main()
{
    char a[] = "hello";
    ft_printf("%s", ft_strchr(a, 'l'));
}*/
