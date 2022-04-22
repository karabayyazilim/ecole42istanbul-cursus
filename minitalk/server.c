/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:11:56 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/23 17:34:48 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_receive_strlen(int *curr_bit, char **str, int *received, int s)
{
	static int	len_val = 0;

	if (s == SIGUSR2)
		len_val += ft_recursive_power(2, *curr_bit);
	if (*curr_bit == 31)
	{
		*received = 1;
		*str = ft_calloc_exit(len_val + 1, sizeof(char));
		*curr_bit = 0;
		len_val = 0;
		return ;
	}
	(*curr_bit)++;
}

static void	ft_free(int *len_received, char **str, int *i)
{
	*len_received = 0;
	if (str)
	{
		ft_putendl(*str);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

void	sig_handler(int signal)
{
	static int	char_value = 0;
	static int	current_bit = 0;
	static int	len_received = 0;
	static int	index = 0;
	static char	*final_str = 0;

	if (!len_received)
		ft_receive_strlen(&current_bit, &final_str, &len_received, signal);
	else
	{
		if (signal == SIGUSR2)
			char_value += ft_recursive_power(2, current_bit);
		if (current_bit == 7)
		{
			final_str[index++] = char_value;
			current_bit = 0;
			if (char_value == 0)
				return (ft_free(&len_received, &final_str, &index));
			char_value = 0;
			return ;
		}
		current_bit++;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		usleep(100);
}
