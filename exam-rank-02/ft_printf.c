/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:16:31 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/25 12:50:56 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void ft_putstr(char *str, int *res_val)
{
	if (!str)
	{
		ft_putstr("(null)", res_val);
		return ;
	}
	while(*str++)
		*res_val += write(1, &str, 1);
}

void ft_putchar(char str, int *res_val)
{
	res_val += write(1, &str, 1);
}

void ft_putnbr(int number, int *res_val)
{
	unsigned int  index;

	index = 0;
	if (number < 0)
	{
		*res_val += write(1, "-", 1);
		index = number * -1;
	}
	else
		index = number;
	if (index > 9)
		ft_putnbr(index / 10, res_val);
	ft_putchar(index % 10 + '0', res_val);
}

char *convert_base(size_t number, char *base_str)
{
	static char	buffer[40];
	char		*str;
	int			base;

	base = 16;
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


int key_control(char key, va_list value, int *res_val)
{
	if (key == 's')
		ft_putstr(va_arg(value, char *), res_val);
	else if (key == 'd')
		ft_putnbr(va_arg(value, int), res_val);
	else if (key == 'x')
		ft_putstr(convert_base(va_arg(value, unsigned int), \
		"0123456789abcdef"), res_val);
	return (0);
}

int ft_printf(const char *str, ...)
{
	int res_val;
	int is_empty;
	va_list list;

	res_val = 0;
	is_empty = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			while (*(++str) == ' ')
				is_empty = 1;
			if (is_empty)
				ft_putchar(' ', &res_val);
			if (key_control(*str, list, &res_val))
				res_val += write(1, str, 1);
		}
		else
			res_val += write(1, str, 1);
		str++;
	}
	va_end(list);
	return (res_val);
}

int main()
{
	int c = ft_printf("x %d\n", -133);
	printf("%d", c);
}