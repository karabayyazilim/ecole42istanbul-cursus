/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:28:15 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:16:57 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char	*dst, const char *src, size_t	dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	if (!dstsize)
		return (srcsize);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

/*
int main()
{
    char a[] = "";
    char b[] = "ali karabay";
    printf("%zu", ft_strlcpy(a, b, 2));
    //printf("%zu", strlcpy("ali", "a", 2));
}*/
