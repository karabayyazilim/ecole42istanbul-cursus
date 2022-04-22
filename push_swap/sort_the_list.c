/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:38:52 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/18 23:36:42 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pivot değerleri bulacak
int	make_pivot(t_data *str)
{
	int		index;
	long	min;
	long	max;

	index = 0;
	min = INT_MAX;
	max = INT_MIN;
	while (index++ < str->size)
	{
		if (str->array[str->size - index] > max)
			max = str->array[str->size - index];
		if (str->array[str->size - index] < min)
			min = str->array[str->size - index];
	}
	return ((max + min) / 2);
}

//bulunan pivot değeri altındakileri pushlanacak
void	send_b(t_data *data_a, t_data *data_b)
{
	int	pivot;
	int	index;
	int	total_numbers;

	index = 0;
	total_numbers = data_a->size;
	pivot = make_pivot(data_a);
	if (data_a->size < 3)
		return ;
	while (total_numbers > index)
	{
		if (data_a->array[data_a->size - 1] <= pivot)
			push(data_a, data_b);
		else
			rotate(data_a, 0);
		index++;
	}
	send_b(data_a, data_b);
}

//eğer b stağindeki değerin a daki yeri bulunmazsa en yüksek değer geri dönecek
int	find_max_value(t_data *data_a)
{
	int	max;
	int	index;
	int	two_index;

	two_index = 0;
	max = INT_MIN;
	while (two_index < data_a->size)
	{
		if (data_a->array[two_index] > max)
		{
			max = data_a->array[two_index];
			index = two_index;
		}
		two_index++;
	}
	return (index);
}

//b stağindeki değerin a daki en uygun index numarası
int	find_index(t_data *data_a, int numb)
{
	int	min;
	int	diff;
	int	index;
	int	two_index;

	two_index = 0;
	min = INT_MAX;
	index = -1;
	while (two_index < data_a->size)
	{
		diff = data_a->array[data_a->size - 1 - index] - numb;
		if (diff < min && diff > 0)
		{
			min = diff;
			index = two_index;
		}
		two_index++;
	}
	if (index == -1)
		index = find_max_value(data_a);
	return (index);
}

/*en kısa yolu bulan fonksiyon, b deki her değer için a daki
* yollar hesaplanır takibinde en kısası işlem görür*/
void	find_sort_path(t_data *data_a, t_data *data_b, int *index_a, int *index_b)
{
	int	tmp[2];
	int	index;
	int	two_index;
	int	min;

	min = INT_MAX;
	index = -1;
	while (++index < data_b->size)
	{
		two_index = find_index(data_a, data_b->array[data_b->size - index - 1]);
		if (index < data_b->size / 2)
			tmp[0] = index;
		else
			tmp[0] = data_b->size - index - 1;
		if (two_index < data_a->size / 2)
			tmp[1] = two_index;
		else
			tmp[1] = data_a->size - two_index - 1;
		if (tmp[0] + tmp[1] < min)
		{
			min = tmp[0] + tmp[1];
			*index_b = index;
			*index_a = two_index;
		}
	}
}
