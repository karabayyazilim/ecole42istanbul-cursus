/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:27:59 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/12 20:27:40 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	index;

	index = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		index = n * -1;
	}
	else
		index = n;
	if (index > 9)
		ft_putnbr_fd(index / 10, fd);
	ft_putchar_fd(index % 10 + '0', fd);
}
