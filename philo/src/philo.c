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

static t_bool	wait_or_die(t_philo *this, uint64_t ms)
{
	if ((this->last_meal + ms) >= this->state->conf.starvation_delay)
	{
		if (this->last_meal < this->state->conf.starvation_delay)
			usleep(((this->last_meal + ms) - this->state->conf.starvation_delay) * 1000);
		return (FALSE);
	}
	usleep(ms * 1000);
	return (TRUE);
}

static void	think(t_philo *this)
{
	philo_print(this, "is thinking");
	// TODO: DECIDE WHAT TO DO
}

static t_bool	blackout(t_philo *this)
{
	philo_print(this, "is sleeping");
	if (!wait_or_die(this, this->state->conf.sleeping_duration))
		return (FALSE);
	think(this);
	return (TRUE);
}

static t_bool	eat(t_philo *this)
{
	pthread_mutex_lock(&(this->left_fork->mutex));
	philo_print(this, "has taken a fork");
	pthread_mutex_lock(&(this->right_fork->mutex));
	philo_print(this, "has taken a fork");
	philo_print(this, "is eating");
	usleep(this->state->conf.eating_duration * 1000);
	pthread_mutex_unlock(&(this->left_fork->mutex));
	pthread_mutex_unlock(&(this->right_fork->mutex));

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
	while (!(this->state->should_stop))
	{
		if (this->last_meal + current_time_ms(this->state->start_time) > this->state->conf.starvation_delay
			|| !eat(this))
		{
			dead = TRUE;
			break ;
		}
	}
	if (dead)
	{
		this->has_died = TRUE;
		philo_print(this, "died");
		this->state->should_stop = TRUE;
	}

	return ((void *)0);
}
