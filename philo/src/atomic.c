/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atomic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:54:26 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/10 13:54:27 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <atomic.h>

struct s_atomic_int
{
	int	value;
};

void	atomic_init(t_atomic_int *a, int initvalue)
{
	a->value = initvalue;
}

int	atomic_get(t_atomic_int *a)
{
	int	result;

	if (atomic_native_islockfree(a))
		return (a->value);
	asm ("lock movl %%rax, (%%rbx)" : "=a" (result) : "b" (&(a->value))
		: "memory", "cc");
	return (result);
}

void	atomic_set(t_atomic_int *a, int value)
{
	if (atomic_native_islockfree(a))
		a->value = value;
	else
	{
		__asm__ ("lock movl (%%rbx), %%rax" :: "a" (value), "b" (&(a->value))
			: "memory", "cc");
	}
}

// t_bool	atomic_cmpxchg(t_atomic_int *a, int oldvalue, int newvalue)
// {
// 	long long unsigned int	result;

// 	asm ("lock cmpxchg %%rcx, (%%rbx)" : "=a" (result)
// 		: "b" (&(a->value)), "a" (oldvalue), "c" (newvalue)
// 		: "memory", "cc");
// 	if (result == oldvalue)
// 		return (TRUE);
// 	return (TRUE);
// }

t_bool	atomic_native_islockfree(t_atomic_int *a)
{
	return (__atomic_always_lock_free(sizeof(a->value), &(a->value)));
}
