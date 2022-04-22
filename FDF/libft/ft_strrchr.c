/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:28:23 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/12 19:13:53 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return ((char *)(str + len));
		len--;
	}
	if (str[len] == (char)c)
		return ((char *)(str + len));
	return (NULL);
}

/*
int main()
{
    char a[] = "hello";
    printf("%s", ft_strrchr(a, 'e'));
}*/
