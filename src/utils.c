#include "../includes/philo.h"

void	print_action(t_rules *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->writting));
	if (!(rules->dead))
		printf("%lli %i %s\n",
	 		timestamp() - rules->first_timestamp,
	 		id + 1,
	 		string);
	pthread_mutex_unlock(&(rules->writting));
	return ;
}

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
