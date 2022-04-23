/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_list2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:38:58 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/23 16:09:20 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	before_single_rotate(t_data *data_a, t_data *data_b, \
int *index_a, int *index_b)
{
	if (*index_a < (data_a->size / 2) && *index_b < (data_b->size / 2))
	{
		while (*index_a > 0 && *index_b > 0)
		{
			rotate_together(data_a, data_b, 0);
			*index_a -= 1;
			*index_b -= 1;
		}
	}
	else if (*index_a >= (data_a->size / 2) && *index_b >= (data_b->size / 2))
	{
		while (*index_a < data_a->size && *index_b < \
		data_b->size && *index_a != 0 && *index_b != 0)
		{
			rev_rotate_together(data_a, data_b, 0);
			*index_a += 1;
			*index_b += 1;
		}
	}
}

// en kısa yoldan dönen index sayıları poslarına göre rotatelenir.
void	send_a(t_data *data_a, t_data *data_b, int index_a, int index_b)
{
	before_single_rotate(data_a, data_b, &index_a, &index_b);
	if (index_a < (data_a->size / 2))
		while (index_a-- > 0)
			rotate(data_a, 0);
	else
		while (index_a++ < data_a->size)
			rev_rotate(data_a, 0);
	if (index_b < (data_b->size / 2))
		while (index_b-- > 0)
			rotate(data_b, 0);
	else
		while (index_b++ < data_b->size)
			rev_rotate(data_b, 0);
	push(data_b, data_a);
}

// sıralama bittikten sonra son kaydırma işlemi
void	get_the_zero(t_data *data_a)
{
	int	index;

	index = 0;
	while (data_a->array[index] != 0)
		index++;
	if (index++ < data_a->size / 2)
		while (index--)
			rev_rotate(data_a, 0);
	else
		while (index++ < data_a->size)
			rotate(data_a, 0);
}

//her şeyin başı
void	sort_the_list(t_data *data_a, t_data *data_b)
{
	int	index_a;
	int	index_b;

	send_b(data_a, data_b);
	while (data_b->size)
	{
		if (data_a->size <= 1)
			push(data_b, data_a);
		find_sort_path(data_a, data_b, &index_a, &index_b);
		send_a(data_a, data_b, index_a, index_b);
	}
	get_the_zero(data_a);
}
