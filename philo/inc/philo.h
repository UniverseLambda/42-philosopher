/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:46 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/10 10:43:54 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_fork.h"
# include "state.h"

# include <stdint.h>

typedef struct s_philo
{
	t_state		*state;
	size_t		philo_id;
	pthread_t	thread;

	t_fork		*left_fork;
	t_fork		*right_fork;
	t_bool		has_died;
	t_bool		terminated;
	uint64_t	last_meal;
}				t_philo;

void	*philo_main(void *philo_ptr);

#endif // PHILO_H
