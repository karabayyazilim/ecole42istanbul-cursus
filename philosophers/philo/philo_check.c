#include "philosophers.h"

int	eat_count_check(t_phdata *ph_data)
{
	if (ph_data->opt_eat_cnt != 0)
	{
		if (ph_data->eat_count == ph_data->opt_eat_cnt)
			return (0);
	}
	return (1);
}

void	die_message(t_phdata *ph_data)
{
	pthread_mutex_lock(ph_data->lock);
	if (!(*(ph_data->is_dead)))
	{
		printf("%lu %d died\n", ph_data->current_time, ph_data->id);
		*ph_data->is_dead = 1;
	}
	pthread_mutex_unlock(ph_data->lock);
}
