/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:52:34 by gangouil          #+#    #+#             */
/*   Updated: 2023/12/21 14:36:39 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_ptr(void *ptr)
{
	int	written;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	written = 2;
	ft_putnbr_base((uint64_t)ptr, 16, "0123456789abcdef", &written);
	return (written);
}

int	handle_lhex(unsigned int n)
{
	int	written;

	written = 0;
	written = ft_putnbr_base(n, 16, "0123456789abcdef", &written);
	return (written);
}

int	handle_uhex(unsigned int n)
{
	int	written;

	written = 0;
	written = ft_putnbr_base(n, 16, "0123456789ABCDEF", &written);
	return (written);
}
