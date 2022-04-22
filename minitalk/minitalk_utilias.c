/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utilias.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:12:10 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/23 17:34:24 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	unsigned int	index;

	index = 0;
	if (n < 0)
	{
		ft_putchar('-');
		index = n * -1;
	}
	else
		index = n;
	if (index > 9)
		ft_putnbr(index / 10);
	ft_putchar(index % 10 + '0');
}

void	*ft_calloc_exit(size_t count, size_t size)
{
	size_t	total_size;
	void	*ret;

	total_size = size * count;
	ret = malloc(total_size);
	if (!ret)
		exit(EXIT_FAILURE);
	ft_bzero(ret, total_size);
	return (ret);
}

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*my_str;

	i = 0;
	my_str = (unsigned char *)(str);
	while (i < n)
	{
		my_str[i] = '\0';
		i++;
	}
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

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
