/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:51:00 by ecabanas          #+#    #+#             */
/*   Updated: 2023/07/06 11:51:21 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	err(char *str)
{
	printf("Error: %s\n", str);
	exit(EXIT_FAILURE);	// Creo que no puedo utilizar esta funcion 'exit';
}
