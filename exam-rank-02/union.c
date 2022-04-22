/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:06:23 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/25 11:25:16 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int use[255];
	int index,sindex;

	if (ac == 3)
	{
		index = 0;
		while (index < 255)
			use[index++] = 0;
		index = 1;
		while (index < 3)
		{
			sindex = 0;
			while (av[index][sindex])
			{
				if (!use[(unsigned char)av[index][sindex]])
				{
					use[(unsigned char)av[index][sindex]] = 1;
					write(1, &av[index][sindex], 1);
				}
				sindex++;
			}
			index++;
		}
	}
	write(1, "\n", 1);
}