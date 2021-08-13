/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_allocator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:36:09 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/12 13:36:09 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ph_allocator.h>
#include <stdlib.h>

typedef struct s_alloc_header
{
	size_t					obj_size;
	t_destructor			destructor;
	struct s_alloc_header	*next;
}				t_alloc_header;

static t_alloc_header	**first_obj()
{
	static t_alloc_header	*first_obj = NULL;

	return (&first_obj);
}

static t_alloc_header	*alloc(size_t count, size_t size)
{
	t_alloc_header	*parent;
	t_alloc_header	*result;

	if ((count * size) / size != count)
		return (NULL);
	parent = *(first_obj());
	result = malloc(sizeof(t_alloc_header) + (count * size));
	if (result == NULL)
		return (NULL);
	result->destructor = NULL;
	result->next = NULL;
	result->obj_size = count * size;
	if (parent == NULL)
		(*first_obj()) = result;
	else
	{
		while (parent->next != NULL)
			parent = parent->next;
		parent->next = result;
	}
	return (result);
}

void	*ph_alloc(size_t count, size_t size)
{
	t_alloc_header	*header;

	header = alloc(count, size);
	return (header + 1);
}

void	*ph_alloc_obj(size_t count, size_t size, t_destructor destructor)
{
	t_alloc_header	*header;

	header = alloc(count, size);
	header->destructor = destructor;
	return (header + 1);
}

void	ph_freemem()
{
	t_alloc_header	*current;
	t_alloc_header	*next;

	current = (*first_obj());
	next = (void *)0xDEADBEEF;
	while (current != NULL)
	{
		next = current->next;
		if (current->destructor != NULL)
			current->destructor(current + 1);
		free(current);
		current = next;
	}
	*first_obj() = NULL;
}
