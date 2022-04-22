/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:38:45 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/18 23:45:29 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_args(t_data *data_a, t_data *data_b)
{
	if (data_a->array[data_a->size - 1] == 0)
	{
		if (data_a->array[data_a->size - 2] == 2)
		{
			push(data_a, data_b);
			if (data_a->array[data_a->size - 1] > data_a->array[data_a->size - 2])
				swap(data_a, 0);
			push(data_b, data_a);
		}
	}
	else if (data_a->array[data_a->size - 2] == 0)
	{
		if (data_a->array[data_a->size - 1] == 2)
			rotate(data_a, 0);
		else if (data_a->array[data_a->size - 1] == 1)
			swap(data_a, 0);
	}
	else if (data_a->array[data_a->size - 3] == 0)
	{
		if (data_a->array[data_a->size - 1] > data_a->array[data_a->size - 2])
			swap(data_a, 0);
		rev_rotate(data_a, 0);
	}
}

void	sort_four_args(t_data *data_a, t_data *data_b)
{
	int	index;

	index = 0;
	if (data_a->size == 4)
	{
		while (data_a->array[index] != 3)
			index++;
		if (index == 0)
			rev_rotate(data_a, 0);
		else
			while (++index < data_a->size)
				rotate(data_a, 0);
		push(data_a, data_b);
		sort_three_args(data_a, data_b);
		push(data_b, data_a);
		rotate(data_a, 0);
	}
	else
	{
		if (data_b->array[data_b->size - 1] > data_b->array[data_b->size - 2])
			swap(data_b, 0);
		sort_three_args(data_a, data_b);
		push(data_b, data_a);
		rotate(data_a, 0);
	}
}

void	sort_five_args_2(t_data *data_a, t_data *data_b, int index)
{
	if (index < 2)
	{
		while (--index >= 0)
		{
			rev_rotate(data_a, 0);
			if (data_a->array[data_a->size - 1] == 3)
				push(data_a, data_b);
		}
	}
	else
	{
		while (++index - 1 < data_a->size)
		{
			rotate(data_a, 0);
			if (data_a->array[data_a->size - 1] == 3)
				push(data_a, data_b);
		}
	}
}

void	sort_five_args(t_data *data_a, t_data *data_b)
{
	int	index;

	index = 0;
	if (data_a->array[data_a->size - 1] == 3)
		push(data_a, data_b);
	while (data_a->array[index] != 4)
		index++;
	index++;
	sort_five_args_2(data_a, data_b, index);
	push(data_a, data_b);
	sort_four_args(data_a, data_b);
	push(data_b, data_a);
	rotate(data_a, 0);
}

void	sort_smaller_list(t_data *data_a, t_data *data_b)
{
	if (data_a->size == 2)
	{
		if (data_a->array[data_a->size - 1] > data_a->array[data_a->size - 2])
			swap(data_a, 0);
	}
	else if (data_a->size == 3)
		sort_three_args(data_a, data_b);
	else if (data_a->size == 4)
		sort_four_args(data_a, data_b);
	else if (data_a->size == 5)
		sort_five_args(data_a, data_b);
}
