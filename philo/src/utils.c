/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:54:29 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/13 13:54:30 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <utils.h>

#include <stddef.h>
#include <sys/time.h>

#include <stdint.h>

#include <stdio.h>

uint64_t	current_time_ms(uint64_t start)
{
	struct timeval	tv;
	uint64_t		result;

	if (gettimeofday(&tv, NULL) != 0)
		puts("WOOPS");
	result = tv.tv_sec * 1000;
	result += tv.tv_usec / 1000;
	if (start != (size_t)(-1))
		result -= start;
	return (result);
}

void	philo_print(t_philo *philo, const char *msg)
{
	pthread_mutex_lock(&(philo->state->speak_lock));
	printf("%llu %zu %s\n",
		current_time_ms(philo->start_time), philo->philo_id, msg);
	pthread_mutex_unlock(&(philo->state->speak_lock));
}
