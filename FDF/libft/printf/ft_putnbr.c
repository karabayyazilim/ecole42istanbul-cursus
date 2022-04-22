/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:56:11 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/02 14:27:41 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *res_val)
{
	unsigned int	index;

	index = 0;
	if (nb < 0)
	{
		ft_putchar('-', res_val);
		index = nb * -1;
	}
	else
		index = nb;
	if (index > 9)
		ft_putnbr(index / 10, res_val);
	ft_putchar(index % 10 + '0', res_val);
}

void	ft_put_u(unsigned int number, int *res_val)
{
	char	str[10];
	int		index;

	index = 0;
	if (number == 0)
		ft_putchar('0', res_val);
	while (number)
	{
		str[index++] = number % 10 + '0';
		number /= 10;
	}
	while (index--)
		ft_putchar(*(str + index), res_val);
}
