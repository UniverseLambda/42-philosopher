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

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}				t_fork;

t_fork	*new_fork(void);
void	delete_fork(t_fork *fork);
void	acquire_fork(t_fork *fork);
void	release_fork(t_fork *fork);

#endif // PHILO_FORK_H
