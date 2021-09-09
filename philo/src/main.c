/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:54:29 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/10 13:54:30 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <conf.h>
#include <philo.h>
#include <ph_allocator.h>
#include <utils.h>

#include <state.h>

#include <stdio.h>

#include <unistd.h>

static t_bool	init_forks(t_state *state)
{
	size_t	i;

	i = -1;
	state->philos[0].left_fork = NULL;
	while (++i < state->philo_count)
	{
		if (!init_fork(&(state->philos[i].right_fork)))
			return (FALSE);
		if (i > 0)
			state->philos[i].left_fork = &(state->philos[i - 1].right_fork);
		if (state->philo_count == 1 && state->philos[0].left_fork == NULL)
		{
			state->philos[i].left_fork = &(state->philos[i - 1].right_fork);
			--i;
		}
	}
	if (state->philo_count > 1)
		state->philos[0].left_fork = &(state->philos[i - 1].right_fork);
	else
		state->philos[0].left_fork = &(state->philos[0].right_fork);
	return (TRUE);
}

static t_bool	here_come_the_philos(t_state *state)
{
	size_t	i;

	i = -1;
	state->start_time = current_time_ms(-1);
	while (++i < state->philo_count)
	{
		state->philos[i].philo_id = i + 1;
		state->philos[i].state = state;
		state->philos[i].last_meal = 0;
		state->philos[i].start_time = state->start_time;
		state->philos[i].meal_count = 0;
		if (pthread_mutex_init(&(state->philos[i].meal_lock), NULL) != 0)
			return (FALSE);
		if (pthread_mutex_init(&(state->philos[i].meal_count_lock), NULL) != 0)
			return (FALSE);
	}
	i = -1;
	while (++i < state->philo_count)
		if (pthread_create(&(state->philos[i].thread), NULL, philo_main,
				&(state->philos[i])) != 0
			|| pthread_detach(state->philos[i].thread) != 0)
			return (FALSE);
	return (TRUE);
}

static t_bool	exec_loop(t_state *state, t_conf *conf)
{
	size_t	i;
	t_bool	everyone_ate;

	i = 0;
	everyone_ate = conf->rec_defined;
	while (i < state->philo_count)
	{
		if (current_time_ms(state->start_time)
			- get_last_meal(&(state->philos[i])) >= conf->starvation_delay)
		{
			state->stop = TRUE;
			pthread_mutex_lock(&(state->speak_lock));
			printf("%llu %zu died\n",
				current_time_ms(state->start_time), i + 1);
			return (FALSE);
		}
		everyone_ate &= (get_meal_count(&(state->philos[i]))
				>= state->conf.required_eat_count);
		++i;
	}
	if (everyone_ate)
		pthread_mutex_lock(&(state->speak_lock));
	return (!everyone_ate);
}

static t_bool	exec_conf(t_conf conf)
{
	t_state	state;

	state.philo_count = conf.philosopher_count;
	state.conf = conf;
	state.stop = FALSE;
	if (pthread_mutex_init(&(state.speak_lock), NULL) != 0)
		return (FALSE);
	state.philos = ph_alloc(state.philo_count, sizeof(t_philo));
	if (state.philos == NULL || !init_forks(&state)
		|| !here_come_the_philos(&state))
		return (FALSE);
	while (exec_loop(&state, &conf))
		;
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_ld_result	result;
	t_bool		ret;

	result = ld_conf(argc, argv);
	if (!result.ok)
	{
		if (result.err_message != NULL)
			printf("Error: %s\n", result.err_message);
		else
			printf("An unknown error occured\n");
		return (1);
	}
	if (result.conf.rec_defined && result.conf.required_eat_count == 0)
		return (0);
	ret = exec_conf(result.conf);
	ph_freemem();
	if (!ret)
		return (1);
	return (0);
}
