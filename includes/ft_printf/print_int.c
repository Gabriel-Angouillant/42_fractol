/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:53:36 by gangouil          #+#    #+#             */
/*   Updated: 2023/11/08 23:09:51 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(uint64_t n, int base, char *table, int *written)
{
	char	c;

	if (n / base != 0)
		ft_putnbr_base(n / base, base, table, written);
	if (base == 10)
		c = n % 10 + '0';
	else
		c = table[n % base];
	(*written)++;
	ft_putchar_fd(c, 1);
	return (*written);
}

int	handle_int(int n)
{
	int		written;

	written = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", 1);
			return (11);
		}
		ft_putchar_fd('-', 1);
		n = -n;
		written++;
	}
	written = ft_putnbr_base((uint64_t)n, 10, "012356789", &written);
	return (written);
}

int	handle_uint(unsigned int n)
{
	int	written;

	written = 0;
	written = ft_putnbr_base((uint64_t)n, 10, "0123456789", &written);
	return (written);
}
