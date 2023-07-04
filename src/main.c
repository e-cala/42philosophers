#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 5 && argc != 6)
		err(ERR_ARGS);
	init_rules(&rules, argv);
	if (launcher(&rules))
		err("There was an error creating the threads");
	return (0);
}
