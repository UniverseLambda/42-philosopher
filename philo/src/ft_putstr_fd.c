/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:58:34 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:58:35 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	read_count;
	ssize_t	length;

	length = 0;
	while (s[length])
		++length;
	read_count = write(fd, s, length);
	while (read_count != -1)
	{
		length -= read_count;
		if (length <= 0)
		{
			return ;
		}
		read_count = write(fd, s, length);
	}
}
