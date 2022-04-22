/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:27:45 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:31:10 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*str1 == *str2 && ++i < n)
	{
		str1++;
		str2++;
	}
	return ((int)(*str1 - *str2));
}

/*int main()
{
    char a[] = "furkan";
    char b[] = "fyrkan";
    printf("%d\n", ft_memcmp(a, b, 3));
    printf("%d\n", memcmp(a, b, 3));
}*/
