/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:06:19 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:06:20 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <utils.h>

static void	print_digit(unsigned int digit, int fd)
{
	ft_putchar_fd((digit % 10) + '0', fd);
}

static int	count_digits(uint64_t nb)
{
	int	count;

	count = 1;
	while ((nb / 10) != 0)
	{
		nb /= 10;
		++count;
	}
	return (count);
}

void	ft_putnbr_fd(uint64_t nb, int fd)
{
	uint64_t		temp_holder;
	int				digit_count;
	int				sub_index;

	digit_count = count_digits(nb);
	while (--digit_count >= 0)
	{
		temp_holder = nb;
		sub_index = 0;
		while (sub_index++ < digit_count)
		{
			temp_holder /= 10;
		}
		temp_holder %= 10;
		print_digit(temp_holder, fd);
	}
}
