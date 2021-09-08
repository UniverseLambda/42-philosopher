/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*                                                                            */
/*   corruption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:04:10 by clsaad            #+#    #+#             */
/*   Updated: 2021/09/08 11:04:11 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*corr_malloc(size_t size)
{
	return (malloc(size));
}

void	corr_free(void *ptr)
{
	free(ptr);
}
