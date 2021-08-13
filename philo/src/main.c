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

#include <state.h>

#include <stdio.h>

static void	fork_dtor(void *vfork)
{
	t_fork	*fork;

	fork = vfork;
	if (fork->valid)
		pthread_mutex_destroy(&(fork->mutex));
}

static t_bool	init_forks(t_state *state)
{
	size_t	i;
	t_fork	*fork;

	i = -1;
	state->philos[0].left_fork = NULL;
	while (++i < state->philo_count)
	{
		fork = ph_alloc_obj(1, sizeof(t_fork), fork_dtor);
		if (fork == NULL)
			return (FALSE);
		fork->valid = pthread_mutex_init(&(fork->mutex), NULL) == 0;
		if (!(fork->valid))
			return (FALSE);
		state->philos[i].right_fork = fork;
		if (i > 0)
			state->philos[i].left_fork = state->philos[i - 1].right_fork;
		if (state->philo_count == 1 && state->philos[0].left_fork == NULL)
		{
			state->philos[i].left_fork = state->philos[i].right_fork;
			--i;
		}
	}
	if (state->philo_count > 1)
		state->philos[0].left_fork = state->philos[i - 1].right_fork;
	return (TRUE);
}

static t_bool here_come_the_philos(t_state *state)
{
	size_t	i;

	i = 0;
	while (i < state->philo_count)
	{
		state->philos[i].philo_id = i + 1;
		state->philos[i].state = state;
		state->philos[i].has_died = FALSE;
		if (pthread_create(&(state->philos[i].thread), NULL, philo_main, &(state->philos[i])) != 0)
			return (FALSE);
		if (pthread_detach(state->philos[i].thread) != 0)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static t_bool	exec_conf(t_conf conf)
{
	t_state	state;

	state.ready = FALSE;
	state.philo_count = conf.philosopher_count;
	state.philos = ph_alloc(state.philo_count, sizeof(t_philo));
	if (state.philos == NULL)
		return (FALSE);
	if (!init_forks(&state))
		return (FALSE);
	if (!here_come_the_philos(&state))
		return (FALSE);
	state.ready = TRUE;
	for (size_t i = 0; i < state.philo_count; ++i)
	{
		while (TRUE)
		{
			if (state.philos[i].has_died)
				break ;
			asm volatile("pause" ::: "memory");
		}
	}

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

	printf("philosopher_count:  %lu\n", result.conf.philosopher_count);
	printf("starvation_delay:   %lu\n", result.conf.starvation_delay);
	printf("eating_duration:    %lu\n", result.conf.eating_duration);
	printf("sleeping_duration:  %lu\n", result.conf.sleeping_duration);
	printf("rec_defined:        %s\n", (result.conf.rec_defined)? "true": "false");
	printf("required_eat_count: %lu\n", result.conf.required_eat_count);

	ret = exec_conf(result.conf);
	ph_freemem();
	if (!ret)
		return (1);
	return (0);
}
