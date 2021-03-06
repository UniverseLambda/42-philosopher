/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:16:13 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/10 10:16:14 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FORK_H
# define PHILO_FORK_H

# include <pthread.h>
# include <bool.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	t_bool			valid;
}				t_fork;

t_bool	init_fork(t_fork *fork);

#endif
