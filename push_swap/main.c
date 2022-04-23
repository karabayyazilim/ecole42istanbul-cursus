/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:38:06 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/23 16:09:18 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data_a;
	t_data	data_b;

	data_a.type = 'a';
	data_b.type = 'b';
	if (ac == 2)
		for_two_args(av[1], &data_a, &data_b);
	else if (ac > 2 && ac <= 502)
		for_more_args(ac, av, &data_a, &data_b);
	else
		return (0);
	check_double(&data_a, &data_b);
	indexing(&data_a);
	check_listed(&data_a, &data_b);
	if (data_a.size > 5)
		sort_the_list(&data_a, &data_b);
	else
		sort_smaller_list(&data_a, &data_b);
	free(data_a.array);
	free(data_b.array);
	return (0);
}
