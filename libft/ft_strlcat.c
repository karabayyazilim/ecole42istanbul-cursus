/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:28:12 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:19:31 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

// Todo: yapılacak

size_t	ft_strlcat(char *dst, const char *src, size_t	dstsize)
{
	size_t	index;
	size_t	dstlen;
	size_t	srclen;

	index = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (src[index] != '\0' && dstsize > (dstlen + 1))
	{
		dst[dstlen] = src[index];
		index++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (dstlen + ft_strlen((char *)(src + index)));
}

/*int main()
{
    char a[] = "ali";
    char b[] = "karabay";
    ft_printf("%lu\n", strlcat("ali vali", "karabay", 3));
    ft_printf("%lu", ft_strlcat(a, b, 3));
}*/