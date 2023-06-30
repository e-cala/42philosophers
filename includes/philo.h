#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define ERR_ARGS "The number of arguments is invalid" 

typedef struct s_rules
{
	int	num_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;

}	t_rules;

/*		init.c			*/
void	init_rules(t_rules *rules, char **argv);

/*		errors.c		*/
void	err(char *str);

/*		utils.c			*/
void	print_args(t_rules rules);
int	ft_atoi(char *str);

#endif
