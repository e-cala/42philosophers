#include "../includes/philo.h"

void	print_args(t_rules rules)
{
	printf("argv[1] | number of philosophers:		%d\n", rules.num_philos);
	printf("argv[2] | time to die		:		%d\n", rules.time_to_die);
	printf("argv[3] | time to eat		:		%d\n", rules.time_to_eat);
	printf("argv[4] | time to sleep		:		%d\n", rules.time_to_sleep);
	printf("argv[5] | number times must eat	:		%d\n", rules.times_must_eat);
}
/*
void	print_action(t_rules *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->writting));
	printf("%lli ", timestamp());
	pthread_mutex_unlock(&(rules->writting));
}
*/
static bool	is_valid(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;
	
	if (!str)
		return (-1);
	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (is_valid(str[i]))
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (sign * res);
}
