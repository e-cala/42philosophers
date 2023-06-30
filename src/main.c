#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 5)
		err(ERR_ARGS);
	init_rules(&rules, argv);
	print_args(rules);
	return (0);
}
