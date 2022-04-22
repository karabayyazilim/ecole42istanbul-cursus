/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:31:27 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/06 13:08:10 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr(char *str, int *res_val)
{
	if (!str)
	{
		ft_putstr("(null)", res_val);
		return ;
	}
	while (*str)
		*res_val += write(1, str++, 1);
}

void	ft_putchar(char str, int *res_val)
{
	*res_val += write(1, &str, 1);
}

char	*ft_convert_base(size_t number, char *base_str)
{
	static char	buffer[40];
	char		*str;
	int			base;

	base = ft_strlen(base_str);
	str = &buffer[39];
	*str = '\0';
	*--str = base_str[number % base];
	number /= base;
	while (number != 0)
	{
		*--str = base_str[number % base];
		number /= base;
	}
	return (str);
}

void	ft_p_str(unsigned long number, int *res_val)
{
	if (number == 0)
	{
		ft_putstr("0x0", res_val);
		return ;
	}
	ft_putstr("0x", res_val);
	ft_putstr(ft_convert_base(number, "0123456789abcdef"), res_val);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}
