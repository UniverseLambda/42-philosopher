/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:21:33 by clsaad            #+#    #+#             */
/*   Updated: 2021/09/08 14:21:34 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void set_last_meal(t_philo *this, int64_t value)
{
	pthread_mutex_lock(&(this->meal_lock));
	this->last_meal = value;
	pthread_mutex_unlock(&(this->meal_lock));
}

int64_t get_last_meal(t_philo *this)
{
	int64_t	value;

	pthread_mutex_lock(&(this->meal_lock));
	value = this->last_meal;
	pthread_mutex_unlock(&(this->meal_lock));
	return (value);
}
