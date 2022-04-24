/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:38:52 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/24 18:23:38 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	two_index;
	int	max;
	int	index;

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
int	find_index(t_data *data_a, int number)
{
	int	two_index;
	int	min;
	int	diff;
	int	index;

	two_index = 0;
	min = INT_MAX;
	index = -1;
	while (two_index < data_a->size)
	{
		diff = data_a->array[data_a->size - 1 - two_index] - number;
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
	int	m;
	int	n;
	int	min;

	min = INT_MAX;
	m = -1;
	while (++m < data_b->size)
	{
		n = find_index(data_a, data_b->array[data_b->size - m - 1]);
		if (m < data_b->size / 2)
			tmp[0] = m;
		else
			tmp[0] = data_b->size - m - 1;
		if (n < data_a->size / 2)
			tmp[1] = n;
		else
			tmp[1] = data_a->size - n - 1;
		if (tmp[0] + tmp[1] < min)
		{
			min = tmp[0] + tmp[1];
			*index_b = m;
			*index_a = n;
		}
	}
}
