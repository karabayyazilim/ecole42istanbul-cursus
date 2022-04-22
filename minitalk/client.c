/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:12:04 by akarabay          #+#    #+#             */
/*   Updated: 2022/03/01 21:25:50 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_errors(int argc, char **argv)
{
	int	index;

	if (argc != 3)
		return (1);
	index = -1;
	while (argv[1][++index])
	{
		if (!ft_strchr("0123456789", argv[1][index]))
			return (1);
	}
	return (0);
}

void	ft_send_next_bit(unsigned char c, int pid)
{
	int	index;

	index = -1;
	while (++index < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c >>= 1;
		usleep(100);
	}
}

void	ft_send_strlen_bit(int len, int pid)
{
	int	index;

	index = -1;
	while (++index < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str_to_send;
	int		len;
	int		index;

	if (ft_errors(argc, argv))
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	str_to_send = argv[2];
	len = ft_strlen(str_to_send);
	index = -1;
	ft_send_strlen_bit(len, pid);
	while (str_to_send[++index])
		ft_send_next_bit(str_to_send[index], pid);
	ft_send_next_bit(str_to_send[index], pid);
}
