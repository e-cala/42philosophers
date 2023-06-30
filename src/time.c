#include "../includes/philo.h"

long long	timestamp(void)
{
/*
 * tv_sec = time in seconds since the Unix epoch
 * tv_usec = Time in microseconds during the current second
 * To get the timestamp in MILLISECONDS we need to multiply seconds by 1000 
 * and divide microseconds by 1000
 * */
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
