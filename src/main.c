/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:53:18 by ecabanas          #+#    #+#             */
/*   Updated: 2023/07/06 11:53:22 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
