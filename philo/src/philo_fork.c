/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:25:19 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/17 14:25:19 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philo_fork.h>
#include <ph_allocator.h>

t_bool	init_fork(t_fork *fork)
{
	fork->valid = pthread_mutex_init(&(fork->mutex), NULL) == 0;
	if (!fork->valid)
		return (FALSE);
	return (TRUE);
}

void	delete_fork(void *vfork)
{
	t_fork	*fork;

	fork = vfork;
	if (fork->valid)
		pthread_mutex_destroy(&(fork->mutex));
}

void	acquire_fork(t_fork *fork)
{
	(void)fork;
}

void	release_fork(t_fork *fork)
{
	(void)fork;
}
