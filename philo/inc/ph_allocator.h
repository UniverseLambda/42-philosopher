/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_allocator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:36:09 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/12 13:36:09 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_ALLOCATOR_H
# define PH_ALLOCATOR_H

# include <bool.h>
# include <stddef.h>

typedef void	(*t_destructor)(void *);

void	*ph_alloc(size_t count, size_t size);
void	*ph_alloc_obj(size_t count, size_t size, t_destructor destructor);

void	ph_freemem(void);

#endif
