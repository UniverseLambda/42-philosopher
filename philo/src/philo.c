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

static void	lock_forks(t_philo *this)
{
	if ((this->philo_id % 2) != 0)
	{
		pthread_mutex_lock(&(this->left_fork->mutex));
		philo_print(this, "has taken a fork");
		pthread_mutex_lock(&(this->right_fork->mutex));
		philo_print(this, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(this->left_fork->mutex));
		philo_print(this, "has taken a fork");
		pthread_mutex_lock(&(this->right_fork->mutex));
		philo_print(this, "has taken a fork");
	}
	set_last_meal(this, current_time_ms(this->start_time));
	inc_meal_count(this);
	philo_print(this, "is eating");
}

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
	lock_forks(this);
	usleep(this->state->conf.eating_duration * 1000);
	pthread_mutex_unlock(&(this->left_fork->mutex));
	pthread_mutex_unlock(&(this->right_fork->mutex));
	return (blackout(this));
}

void	*philo_main(void *philo_ptr)
{
	t_philo	*this;
	t_bool	dead;

	this = philo_ptr;
	dead = FALSE;
	if ((this->philo_id % 2) != 0)
		eat(this);
	else
		think(this);
	while (1)
		eat(this);
	return ((void *)0);
}
