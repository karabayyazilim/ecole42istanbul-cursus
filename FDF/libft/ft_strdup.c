/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:28:08 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:21:06 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	return (ft_memcpy(str, s1, len));
}

/*
int main()
{
    printf("%s", ft_strdup("ali karabay"));
}*/
