/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:27:26 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:34:34 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)s++ = 0;
}

/*int main()
{
    char a[] = "ali";
    char c[] = "ali";
    ft_bzero(a + 1, 2);
    bzero(c + 1, 2);
    printf("%s\n", a);
    printf("%s", c);
}*/
