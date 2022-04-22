/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:28:29 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/13 12:37:34 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	index;

	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	index = 0;
	while (len--)
		res[index++] = s[start++];
	res[index] = '\0';
	free(s);
	return (res);
}

/*
int main()
{
    ft_printf("%s", ft_substr("abcdef", 2, 1));
}*/
