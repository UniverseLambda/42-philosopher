/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:57:58 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:57:59 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	write_count;

	write_count = write(fd, &c, 1);
	while (write_count != -1)
	{
		if (write_count > 0)
		{
			return ;
		}
		write_count = write(fd, &c, 1);
	}
}
