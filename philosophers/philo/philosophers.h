/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:43:26 by akarabay          #+#    #+#             */
/*   Updated: 2022/08/28 18:43:35 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct philosophers_atbs
{
	int							id;
	int							total_philo;
	int							die_time;
	int							eat_time;
	int							sleep_time;
	int							opt_eat_cnt;
	int							eat_count;
	int							*is_dead;
	int							*count;
	unsigned long int			current_time;
	unsigned long int			last_eat_philo;
	unsigned long int			ms;
	unsigned long int			start;
	pthread_t					thread;
	pthread_mutex_t				*lock;
	pthread_mutex_t				*fork;
	pthread_mutex_t				*right_fork;
	pthread_mutex_t				*left_fork;
}								t_phdata;

int		arg_check(char **av);
int		ft_atoi(const char *s);
void	*table(void *ph_data);
void	ft_mutex_init(t_phdata *ph_data, char **av);
void	create_philo(t_phdata *ph_data);
void	set_value(t_phdata *ph_data, char **av);
void	*eating(t_phdata *ph_data);
void	sleeping(t_phdata *ph_data);
void	thinking(t_phdata *ph_data);
void	die_message(t_phdata *ph_data);
int		eat_count_check(t_phdata *ph_data);
int		fake_sleep(t_phdata *ph_data, int time);
void	ft_free(t_phdata *ph_data);

#endif