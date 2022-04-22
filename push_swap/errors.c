/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:37:51 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/15 14:49:31 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_mes(t_data *data_a, t_data *data_b)
{
	ft_printf("Error\n");
	free(data_a->array);
	free(data_b->array);
	exit(1);
}
