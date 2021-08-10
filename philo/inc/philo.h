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

typedef struct s_philo
{
	pthread_t	thread;

	t_fork		*left_fork;
	t_fork		*right_fork;
}				t_philo;

#endif // PHILO_H
