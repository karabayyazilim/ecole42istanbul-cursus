/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:24:15 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/06 13:19:39 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_key_control(char key, va_list value, int *res_val)
{
	if (key == 's')
		ft_putstr(va_arg(value, char *), res_val);
	else if (key == 'c')
		ft_putchar(va_arg(value, int), res_val);
	else if (key == 'd')
		ft_putnbr(va_arg(value, int), res_val);
	else if (key == 'i')
		ft_putnbr(va_arg(value, int), res_val);
	else if (key == 'x')
		ft_putstr(ft_convert_base(va_arg(value, unsigned int), \
		"0123456789abcdef"), res_val);
	else if (key == 'X')
		ft_putstr(ft_convert_base(va_arg(value, unsigned int), \
		"0123456789ABCDEF"), res_val);
	else if (key == 'p')
		ft_p_str(va_arg(value, unsigned long), res_val);
	else if (key == 'u')
		ft_put_u(va_arg(value, unsigned int), res_val);
	else if (key == '%')
		ft_putchar('%', res_val);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		is_empty;
	int		res_val;

	is_empty = 0;
	res_val = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			while (*(++str) == ' ')
				is_empty = 1;
			if (is_empty)
				ft_putchar(' ', &res_val);
			if (ft_key_control(*str, list, &res_val))
				res_val += write(1, str, 1);
		}
		else
			res_val += write(1, str, 1);
		str++;
	}
	va_end(list);
	return (res_val);
}

//int main()
//{
//    //ft_printf("s --> %s\n", "ali karabay");
//    //ft_printf("c --> %c\n", 'a');
//    //ft_printf("d --> %d\n", 123);
//    //ft_printf("i --> %i\n", 4234);
//    //ft_printf("x --> %x\n", 23423);
//    //ft_printf("X --> %X\n", 342);
//    //ft_printf("p --> %p\n", 777);
//    ft_printf("u --> %u\n", 896986428952);
//    //ft_printf("percent --> %%%%%\n");
//}
