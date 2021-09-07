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

#include <utils.h>
#include <stdio.h>

#include <unistd.h>

static void	think(t_philo *this)
{
	philo_print(this, "is thinking");
}

static void	blackout(t_philo *this)
{
	philo_print(this, "is sleeping");
	usleep(this->state->conf.sleeping_duration * 1000);
	think(this);
}

static void	eat(t_philo *this)
{
	pthread_mutex_lock(&(this->left_fork->mutex));
	philo_print(this, "has taken a fork");
	pthread_mutex_lock(&(this->right_fork->mutex));
	philo_print(this, "has taken a fork");
	pthread_mutex_lock(&(this->meal_lock));
	this->can_die = FALSE;
	pthread_mutex_unlock(&(this->meal_lock));
	philo_print(this, "is eating");
	usleep(this->state->conf.eating_duration * 1000);
	pthread_mutex_unlock(&(this->left_fork->mutex));
	pthread_mutex_unlock(&(this->right_fork->mutex));
	pthread_mutex_lock(&(this->meal_lock));
	this->last_meal = current_time_ms(this->start_time);
	this->can_die = TRUE;
	pthread_mutex_unlock(&(this->meal_lock));
	return (blackout(this));
}

void	*philo_main(void *philo_ptr)
{
	t_philo	*this = philo_ptr;
	t_bool	dead;

	dead = FALSE;
	this->last_meal = this->state->start_time;
	if ((this->philo_id % 2) != 0)
		eat(this);
	else
		think(this);
	while (1)
		eat(this);
	return ((void *)0);
}
