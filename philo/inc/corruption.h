/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corruption.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:05:16 by clsaad            #+#    #+#             */
/*   Updated: 2021/09/08 11:05:17 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORRUPTION_H
# define CORRUPTION_H

# include <stddef.h>

void	*corr_malloc(size_t size);
void	corr_free(void *ptr);

#endif
