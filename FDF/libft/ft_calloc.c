/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:27:29 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:34:20 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = (char *)malloc(count * size);
	if (!str)
		return (0);
	return (ft_memset(str, 0, count * size));
}

/*
int main()
{
    int *a = ft_calloc(3, sizeof(int));
    printf("%d", *a);
}*/
