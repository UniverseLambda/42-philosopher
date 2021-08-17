/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:54:29 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/13 13:54:30 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include <bool.h>
# include <stddef.h>

# include "conf.h"

typedef struct s_philo t_philo;

typedef struct s_state
{
	t_philo		*philos;
	size_t		philo_count;
	t_bool		ready;
	t_conf		conf;
	t_bool		should_stop;
	uint64_t	start_time;
}				t_state;

#endif // STATE_H