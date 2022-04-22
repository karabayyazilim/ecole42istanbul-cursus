/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:27:47 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:30:02 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

/*int main() {
    char a[10] = "";
    char b[] = "ali";
    char a1[10] = "";
    char b1[] = "ali";

    ft_memcpy(a, b, 2);
    ft_printf("benim --> %s\n\n", a);
    memcpy(a1, b1, 2);
    ft_printf("orginal --> %s", a);
}*/
