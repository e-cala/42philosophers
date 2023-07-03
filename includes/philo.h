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
	int				id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	long long		t_last_meal;
	struct s_rules	*rules;
	pthread_t		thread_id;
}					t_philosopher;

typedef struct s_rules
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				dead;
	long long		first_timestamp;
	pthread_mutex_t	writting;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	meal_check;
	t_philosopher	philosophers[250];
}					t_rules;

/*		init.c			*/
void	init_rules(t_rules *rules, char **argv);

/*		launcher.c		*/

int	launcher(t_rules *rules);

/*		errors.c		*/
void	err(char *str);

/*		time.c			*/
long long	timestamp(void);
void		smart_sleep(long long time, t_rules *rules);

/*		utils.c			*/
void	print_args(t_rules rules);
void	print_action(t_rules *rules, int id, char *string);
int		ft_atoi(char *str);

#endif
