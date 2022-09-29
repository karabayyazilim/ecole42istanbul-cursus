/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behaviours.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:43:02 by akarabay          #+#    #+#             */
/*   Updated: 2022/08/28 18:43:35 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	get_time(t_phdata *ph_data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	ph_data->ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (ph_data->start == 0)
		ph_data->start = ph_data->ms;
	ph_data->current_time = ph_data->ms - ph_data->start;
}

int	fake_sleep(t_phdata *ph_data, int time)
{
	unsigned long int	c_time;

	get_time(ph_data);
	c_time = ph_data->current_time;
	while (ph_data->current_time < c_time + time)
	{
		get_time(ph_data);
		if (ph_data->current_time > ph_data->last_eat_philo)
		{
			die_message(ph_data);
			return (1);
		}
		usleep(time);
	}
	return (0);
}

void	thinking(t_phdata *ph_data)
{
	get_time(ph_data);
	pthread_mutex_lock(ph_data->lock);
	if (*ph_data->is_dead != 1)
		printf("%lu %d is thinking\n", ph_data->current_time, ph_data->id);
	pthread_mutex_unlock(ph_data->lock);
	eating(ph_data);
}

void	sleeping(t_phdata *ph_data)
{
	get_time(ph_data);
	pthread_mutex_lock(ph_data->lock);
	if (*ph_data->is_dead != 1)
		printf("%lu %d is sleeping\n", ph_data->current_time, ph_data->id);
	pthread_mutex_unlock(ph_data->lock);
	fake_sleep(ph_data, ph_data->sleep_time);
	thinking(ph_data);
}

void	*eating(t_phdata *ph_data)
{
	if (eat_count_check(ph_data))
	{
		get_time(ph_data);
		pthread_mutex_lock(ph_data->left_fork);
		pthread_mutex_lock(ph_data->right_fork);
		get_time(ph_data);
		pthread_mutex_lock(ph_data->lock);
		if (*ph_data->is_dead != 1)
		{
			printf("%lu %d has taken a fork\
			\n%lu %d has taken a fork\n%lu %d is eating\n", \
			ph_data->current_time, ph_data->id, \
			ph_data->current_time, ph_data->id, \
			ph_data->current_time, ph_data->id);
		}
		pthread_mutex_unlock(ph_data->lock);
		fake_sleep(ph_data, ph_data->eat_time);
		ph_data->eat_count++;
		ph_data->last_eat_philo = ph_data->current_time + ph_data->die_time;
		pthread_mutex_unlock(ph_data->right_fork);
		pthread_mutex_unlock(ph_data->left_fork);
		sleeping(ph_data);
	}
	return (NULL);
}
