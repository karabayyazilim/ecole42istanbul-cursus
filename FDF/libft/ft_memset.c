/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:27:52 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/08 19:25:08 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len-- > 0)
	{
		str[len] = (unsigned char)c;
	}
	return (str);
}

/*int main()
{
    char a[] = "ali";
    char c[] = "ali";
    ft_memset(a, 'b', 2);
    memset(c, 'b', 2);
    printf("%s\n", a);
    printf("%s", c);
}*/
