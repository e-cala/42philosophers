#include "../includes/philo.h"

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->num_philos;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->writting), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (1);
	return (0);

}

int	init_philosophers(t_rules *rules)
{
	int	i;

	i = rules->num_philos;
	while (--i >= 0)
	{
		rules->philosophers[i].id = i;
		rules->philosophers[i].x_ate = 0;
		rules->philosophers[i].left_fork_id = i;
		rules->philosophers[i].right_fork_id = (i + 1) % rules->num_philos;
		rules->philosophers[i].t_last_meal = 0;
		rules->philosophers[i].rules = rules;
	}
	return (0);
}

int	init_rules(t_rules *rules, char **argv)
{
	rules->num_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	rules->all_ate = 0;
	rules->dead = 0;
	if (rules->num_philos < 2 || rules->time_to_die < 0 || rules->time_to_eat < 0 
	|| rules->time_to_sleep < 0 || rules->num_philos > 250)
		return (1);
	if (argv[5])
	{
		rules->times_must_eat = ft_atoi(argv[5]);
		if (rules->times_must_eat <= 0)
		return (1);
	}
	else
		rules->times_must_eat = -1;
	if (init_mutex(rules))
		return (2);
	init_philosophers(rules);
	return (0);
}
