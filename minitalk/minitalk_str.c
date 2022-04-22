/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:59:29 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/23 15:59:35 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (*str++)
		index++;
	return (index);
}

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

void	ft_putendl(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
