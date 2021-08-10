/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:33:16 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/10 14:33:17 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONF_H
# define CONF_H

# include <stdint.h>
# include <stddef.h>

# include "bool.h"

typedef struct s_conf
{
	uint64_t	philosopher_count;
	uint64_t	starvation_delay;
	uint64_t	eating_duration;
	uint64_t	sleeping_duration;
	uint64_t	required_eat_count;
}				t_conf;

typedef struct s_ld_result
{
	t_bool		ok;
	const char	*err_message;
	t_conf		conf;
}				t_ld_result;

t_ld_result	ld_conf(int argc, char *argv[]);

#endif // CONF_H
