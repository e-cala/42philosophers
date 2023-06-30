#include "../includes/philo.h"

void	init_rules(t_rules *rules, char **argv)
{
	rules->num_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (!argv[5])
		rules->times_must_eat = ft_atoi(argv[5]);
}
