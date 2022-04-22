/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:28:21 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:12:43 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	needle_index;
	char	*result;

	index = 0;
	needle_index = 0;
	result = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (result);
	while (result[index] != '\0' && len >= ft_strlen(needle))
	{
		while (result[index + needle_index] == needle[needle_index] && \
		result[index + needle_index] != '\0' && needle[needle_index] != '\0')
			needle_index++;
		if (needle[needle_index] == '\0')
			return (&result[index]);
		index++;
		len--;
	}
	return (NULL);
}

/*
int main()
{
    ft_printf("%s", ft_strnstr("merhaba", "mer", 5));
    return (0);
}*/
