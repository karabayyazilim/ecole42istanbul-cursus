/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:27:49 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/12 18:58:05 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dsts;
	char	*srcs;
	int		index;

	index = 0;
	dsts = (char *)dst;
	srcs = (char *)src;
	if (dsts == srcs)
		return (dst);
	if (srcs < dsts)
	{
		while (len-- > 0)
			*(dsts + len) = *(srcs + len);
		return ((void *)dsts);
	}
	while (index < (int)len)
	{
		dsts[index] = srcs[index];
		index++;
	}
	return ((void *)dsts);
}

/*int main()
{
    char dst[] = "bikgisayar";
    char src[] = "bilgisayar1";

    char dst2[] = "bilgisayar";
    char src2[] = "bilgisayar1";

    ft_memmove(dst, src, 10);
    memmove(dst2, src2, 10);

    printf("%s\n", dst);
    printf("%s", dst2);
}*/
