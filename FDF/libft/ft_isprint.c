/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:27:40 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:32:17 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
int main()
{
    int var1 = 'k';
    int var2 = '8';
    int var3 = '\t';
    int var4 = ' ';

    printf("%d", ft_isprint(var1));
    printf("%d", ft_isprint(var2));
    printf("%d", ft_isprint(var3));
    printf("%d", ft_isprint(var4));
}*/
