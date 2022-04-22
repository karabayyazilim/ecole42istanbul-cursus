/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:38:25 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/17 19:21:32 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_together(t_data *data_a, t_data *data_b, int control)
{
	if (control == 0)
	{
		rev_rotate(data_a, 1);
		rev_rotate(data_b, 1);
		ft_printf("rrr\n");
	}
}

void	rev_rotate(t_data *data, int control)
{
	int	index;
	int	tmp;

	index = 0;
	tmp = data->array[0];
	while (index < data->size)
	{
		data->array[index] = data->array[index + 1];
		index++;
	}
	data->array[data->size - 1] = tmp;
	if (control == 0)
	{
		if (data->type == 'a')
			ft_printf("rra\n");
		else if (data->type == 'b')
			ft_printf("rrb\n");
	}
}
