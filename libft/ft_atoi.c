/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:24:53 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:36:56 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char	*str)
{
	int				negative;
	long long int	res;

	negative = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' \
			|| *str == '\f' || *str == '\r')
			str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		res = (res * 10) + (*str - 48) * negative;
		str++;
		if (res > 2147483647)
			return (-1);
		if (res < -2147483648)
			return (0);
	}
	return (res);
}

/*
int main()
{
    ft_printf("%d\n", ft_atoi("!-1231"));
    ft_printf("%d", atoi("!-1231"));
    return (0);
}*/
