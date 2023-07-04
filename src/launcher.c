#include "../includes/philo.h"

void	philo_eats(t_philosopher *philo)
{
	t_rules *rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	print_action(rules, philo->id, "has taken a fork");
	
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	print_action(rules, philo->id, "has taken a fork");
	
	pthread_mutex_lock(&(rules->meal_check));
	print_action(rules, philo->id, "is eating");

	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	smart_sleep(rules->time_to_eat, rules);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));

}

void	*p_thread(void *void_philosopher)
{
	int				i;
	t_philosopher	*philo;
	t_rules			*rules;

	i = 0;
	philo = (t_philosopher *) void_philosopher;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->dead))
	{
		philo_eats(philo);
		if (rules->all_ate)
			break ;
		print_action(rules, philo->id, "is sleeping");
		smart_sleep(rules->time_to_sleep, rules);
		print_action(rules, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

void	exit_launcher(t_rules *rules, t_philosopher *philo)
{
	int	i;

	i = -1;
	while (++i <rules->num_philos)
		pthread_join(philo[i].thread_id, NULL);
	i = -1;
	while (++i < rules->num_philos)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writting));
}

void	death_checker(t_rules *rules, t_philosopher *philo)
{
	int	i;

	while (!(rules->all_ate))
	{
		i = -1;
		while (++i < rules->num_philos && !(rules->dead))
		{
			pthread_mutex_lock(&(rules->meal_check));
			if (time_diff(philo[i].t_last_meal, timestamp()) > rules->time_to_die)
			{
				print_action(rules, i, "died");
				rules->dead = 1;
			}
			pthread_mutex_unlock(&(rules->meal_check));
			usleep(100);
		}
			if (rules->dead)
				break ;
			i = 0;
			while (rules->times_must_eat != -1 && rules->num_philos && philo[i].x_ate >= rules->times_must_eat)
				i++;
			if (i == rules->num_philos)
				rules->all_ate = 1;
	}
}

int	launcher(t_rules *rules)
{
	int				i;
	t_philosopher	*phi;

	i = 0;
	phi = rules->philosophers;
	while (i < rules->num_philos)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, p_thread, (void *) &(phi[i])))
			return (1);
		phi[i].t_last_meal = timestamp();
		i++;
	}
	death_checker(rules, rules->philosophers);
	exit_launcher(rules, phi);
	return (0);
}
