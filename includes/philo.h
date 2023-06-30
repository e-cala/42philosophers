#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define ERR_ARGS "The number of arguments is invalid" 

typedef struct s_philosopher
{
	int		id;
	long long	t_last_meal;
	struct s_rules	*rules;
	pthread_t	thread_id;
}	t_philosopher;

typedef struct s_rules
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_must_eat;
	int		dead;
	long long	first_timestamp;
	pthread_mutex_t	writting;
	t_philosopher	philosophers[250];
}	t_rules;

/*		init.c			*/
void	init_rules(t_rules *rules, char **argv);

/*		launcher.c		*/:w

int	launcher(t_rules *rules);

/*		errors.c		*/
void	err(char *str);

/*		time.c			*/
long long	timestamp(void);

/*		utils.c			*/
void	print_args(t_rules rules);
int	ft_atoi(char *str);

#endif
