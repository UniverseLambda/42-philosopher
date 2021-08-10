/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atomic.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:36:09 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/10 13:36:09 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOMIC_H
# define ATOMIC_H

# include "bool.h"

typedef struct s_atomic_int	t_atomic_int;

void	atomic_init(t_atomic_int *a, int initvalue);
int		atomic_get(t_atomic_int *a);
void	atomic_set(t_atomic_int *a, int value);

// t_bool	atomic_cmpxchg(t_atomic_int *a, int oldvalue, int newvalue);

t_bool	atomic_native_islockfree(t_atomic_int *a);

#endif // ATOMIC_H
