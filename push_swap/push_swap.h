/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:38:16 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/23 16:09:18 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "./ft_printf/ft_printf.h"
# include "./gnl/get_next_line.h"

typedef struct s_data
{
	int		*array;
	int		size;
	char	type;
}	t_data;

void	swap(t_data *data, int control);
void	rotate(t_data *data, int control);
void	rev_rotate(t_data *data, int control);
void	push(t_data *data1, t_data *data2);
void	sort_the_list(t_data *data_a, t_data *data_b);
void	indexing(t_data *data);
void	rotate_together(t_data *data_a, t_data *data_b, int control);
void	rev_rotate_together(t_data *data_a, t_data *data_b, int control);
void	swap_together(t_data *data_a, t_data *data_b, int control);
void	sort_smaller_list(t_data *data_a, t_data *data_b);
void	error_mes(t_data *data_a, t_data *data_b);
void	send_b(t_data *data_a, t_data *data_b);
void	find_sort_path(t_data *data_a, t_data *data_b, \
int *index_a, int *index_b);
void	check_double(t_data *data_a, t_data *data_b);
void	check_listed(t_data *data_a, t_data *data_b);
void	for_two_args(char *str, t_data *data_a, t_data *data_b);
void	for_more_args(int ac, char **av, t_data *data_a, t_data *data_b);
void	check_listed_for_checker(t_data *data_a, t_data *data_b, int *control);

#endif