#include "philosophers.h"

int	ft_atoi(const char *s)
{
	int				number;
	long int		tmp;

	number = 1;
	tmp = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\v' \
			|| *s == '\f' || *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			number = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		tmp = (tmp * 10) + (*s - '0') * number;
		s++;
		if (tmp > 2147483647)
			return (-1);
		if (tmp < -2147483648)
			return (0);
	}
	return (tmp);
}

void	ft_free(t_phdata *ph_data)
{
	free(ph_data->is_dead);
	free(ph_data->count);
	free(ph_data->lock);
	free(ph_data->fork);
	free(ph_data);
}
