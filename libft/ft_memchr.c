/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:27:42 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:32:01 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	x;

	x = 0;
	while (n-- > 0)
	{
		if (((unsigned char *)s)[x] == (unsigned char)c)
			return ((void *)(s + x));
		x++;
	}
	return (0);
}

/*
int main()
{
    char a[] = "ali";
    ft_memchr(a, 'l', 2);
    ft_printf("%s\n", a);
}*/
