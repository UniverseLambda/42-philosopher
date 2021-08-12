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

#include <stdio.h>

typedef struct s_state
{
	t_philo		*philos;
	size_t		philo_count;
}				t_state;

t_bool	exec_conf(t_conf conf)
{
	t_state	state;

	state.philo_count = conf.philosopher_count;
	state.philos = ph_alloc(state.philo_count, sizeof(t_philo));
	if (state.philos == NULL)
		return (FALSE);

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
