/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:37:43 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/23 16:09:18 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_pros(t_data *data_a, t_data *data_b, char *str)
{
	ft_printf(s);
	if (str[0] == 's' && str[1] == 'a')
		swap(data_a, 1);
	else if (str[0] == 's' && str[1] == 'b')
		swap(data_b, 1);
	else if (str[0] == 's' && str[1] == 's')
		swap_together(data_a, data_b, 1);
	else if (str[0] == 'r' && str[1] == 'a')
		rotate(data_a, 1);
	else if (str[0] == 'r' && str[1] == 'b')
		rotate(data_b, 1);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rev_rotate_together(data_a, data_b, 1);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rev_rotate(data_a, 1);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rev_rotate(data_b, 1);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rev_rotate_together(data_a, data_b, 1);
	else if (str[0] == 'r' && str[1] == 'r')
		rotate_together(data_a, data_b, 1);
	else if (str[0] == 'p' && str[1] == 'a')
		push(data_b, data_a);
	else if (str[0] == 'p' && str[1] == 'b')
		push(data_a, data_b);
}

void	read_lines(t_data *data_a, t_data *data_b)
{
	int		total_line;
	char	*tmp;

	total_line = 0;
	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		make_pros(data_a, data_b, tmp);
	}
}

int	main(int ac, char **av)
{
	t_data	data_a;
	t_data	data_b;
	int		control;

	control = -1;
	data_a.type = 'a';
	data_b.type = 'b';
	if (ac == 2)
		for_two_args(av[1], &data_a, &data_b);
	else if (ac > 2 && ac <= 502)
		for_more_args(ac, av, &data_a, &data_b);
	else
		return (0);
	read_lines(&data_a, &data_b);
	check_listed_for_checker(&data_a, &data_b, &control);
	if (control == 1 && data_a.size == 0)
		ft_printf("OK");
	else if (control == 0 || data_b.size != 0)
		ft_printf("KO");
}
