#include "../includes/philo.h"

void	*p_thread(void *void_philosopher)
{
	int		i;
	t_philosopher	*philo;
	t_rules		*rules;

	i = 0;
	philo = (t_philosopher *) void_philosopher;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->dead))
	{
		//delete printf
		printf("hola\n");
		i++;
	}
	return (NULL);
}

int	launcher(t_rules *rules)
{
	int		i;
	t_philosopher	*phi;

	i = 0;
	phi = rules->philosophers;
	rules->first_timestamp = timestamp();
	while (i < rules->num_philos)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, p_thread, &(phi[i])))
			return (1);
		phi[i].t_last_meal = timestamp();
		i++;
	}
	return (0);
}
