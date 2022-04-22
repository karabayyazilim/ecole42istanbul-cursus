/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:28:45 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/25 11:31:24 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int use[255];
	int index, sindex;

	if (ac == 3)
	{
		index = 0;
		while (index < 255)
			use[index++] = 0;
		index = 2;
		while (index > 0)
		{
			sindex = 0;
			while (av[index][sindex])
			{
				if (index == 2 && !use[(unsigned char)av[index][sindex]])
					use[(unsigned char)av[index][sindex]] = 1;
				else if (index == 1 && use[(unsigned char)av[index][sindex]] == 1)
				{
					write(1, &av[index][sindex],1);
					use[(unsigned char)av[index][sindex]] = 2;
				}
				sindex++;
			}
			index--;
		}
	}
	write(1, "\n",1);
}