/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:43:16 by akarabay          #+#    #+#             */
/*   Updated: 2022/08/28 18:43:35 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	arg_check(char **av)
{
	int	index;
	int	arg;

	arg = 1;
	if (ft_atoi(av[1]) == 0)
		return (0);
	while (av[arg])
	{
		index = 0;
		while (av[arg][index])
		{
			if (av[arg][index] >= '0' && av[arg][index] <= '9')
				index++;
			else
				return (0);
		}
		arg++;
	}
	return (1);
}

void	mini_set(t_phdata *ph_data, char **av)
{
	int	index;

	index = 0;
	while (index < ft_atoi(av[1]))
	{
		ph_data[index].id = index + 1;
		ph_data[index].total_philo = (unsigned long int)ft_atoi(av[1]);
		ph_data[index].die_time = (unsigned long int)ft_atoi(av[2]);
		ph_data[index].eat_time = (unsigned long int)ft_atoi(av[3]);
		ph_data[index].sleep_time = (unsigned long int)ft_atoi(av[4]);
		ph_data[index].last_eat_philo = (unsigned long int)ft_atoi(av[2]);
		ph_data[index].eat_count = 0;
		ph_data[index].opt_eat_cnt = 0;
		if (av[5])
			ph_data[index].opt_eat_cnt = (unsigned long int)ft_atoi(av[5]);
		index++;
	}
}

void	ft_mutex_init(t_phdata *ph_data, char **av)
{
	pthread_mutex_t	*forks;
	int				index;

	index = 0;
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	while (index < ft_atoi(av[1]))
		pthread_mutex_init(&forks[index++], NULL);
	ph_data->fork = forks;
}

void	set_value(t_phdata *ph_data, char **av)
{
	pthread_mutex_t		*locker;
	int					i;
	int					*die;
	int					*full;

	i = -1;
	die = malloc(sizeof(int));
	full = malloc(sizeof(int));
	locker = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(locker, NULL);
	*die = 0;
	*full = 0;
	mini_set(ph_data, av);
	while (++i < ft_atoi(av[1]))
	{
		ph_data[i].left_fork = &ph_data->fork[i];
		ph_data[i].right_fork = &ph_data->fork[i + 1];
		ph_data[i].lock = locker;
		ph_data[i].is_dead = die;
		ph_data[i].count = full;
	}
	ph_data[i - 1].right_fork = &ph_data->fork[0];
	ph_data->current_time = 0;
	ph_data->ms = 0;
	ph_data->start = 0;
}

void	create_philo(t_phdata *ph_data)
{
	int	i;

	i = 0;
	while (i < ph_data->total_philo)
	{
		pthread_create(&ph_data[i].thread, NULL, \
		(void *)table, &ph_data[i]);
		pthread_detach(ph_data[i].thread);
		i += 2;
	}
	i = 1;
	usleep(100);
	while (i < ph_data->total_philo)
	{
		pthread_create(&ph_data[i].thread, NULL, \
		(void *)table, &ph_data[i]);
		pthread_detach(ph_data[i].thread);
		i += 2;
	}
}
