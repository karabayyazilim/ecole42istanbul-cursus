/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:43:23 by akarabay          #+#    #+#             */
/*   Updated: 2022/08/28 18:43:35 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	die_check(t_phdata *ph_data)
{
	while (1)
	{
		pthread_mutex_lock(ph_data->lock);
		if (*ph_data->is_dead)
			return ;
		pthread_mutex_unlock(ph_data->lock);
		usleep(10);
	}
}

void	*table(void *data)
{
	t_phdata	*ph_data;

	ph_data = (t_phdata *)data;
	if (ph_data->total_philo == 1)
	{
		printf("%lu %d has taken a fork\n", \
		ph_data->current_time, ph_data->id);
		usleep(ph_data->die_time * 1000);
		printf("%d %d died\n", ph_data->die_time, ph_data->id);
		pthread_mutex_lock(ph_data->lock);
		*ph_data->is_dead = 1;
		pthread_mutex_unlock(ph_data->lock);
		return (NULL);
	}
	eating(ph_data);
	pthread_mutex_lock(ph_data->lock);
	(*ph_data->count)++;
	if (*ph_data->count == ph_data->total_philo)
		*(ph_data->is_dead) = 1;
	pthread_mutex_unlock(ph_data->lock);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_phdata	*ph_data;

	if ((ac == 5 || ac == 6) && arg_check(av))
	{
		ph_data = (t_phdata *)malloc(sizeof(t_phdata) * ft_atoi(av[1]));
		ft_mutex_init(ph_data, av);
		set_value(ph_data, av);
		create_philo(ph_data);
		die_check(ph_data);
		ft_free(ph_data);
	}
	return (0);
}
