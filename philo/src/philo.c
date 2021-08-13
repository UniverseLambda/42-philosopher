/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:33:24 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/10 14:33:25 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#include <util.h>
#include <stdio.h>

void	*philo_main(void *philo_ptr)
{
	t_philo	*this = philo_ptr;

	printf("Philosopher %zu born at %lu\n", this->philo_id, current_time_ms(-1));
	this->has_died = TRUE;
	return ((void *)0);
}
