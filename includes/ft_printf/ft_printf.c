/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:11:22 by gangouil          #+#    #+#             */
/*   Updated: 2024/01/26 13:22:49 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conv(char c, va_list args)
{
	int	written;

	written = 0;
	if (c == 'c')
		written = handle_char(va_arg(args, unsigned int));
	else if (c == 's')
		written = handle_str(va_arg(args, char *));
	else if (c == 'p')
		written = handle_ptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		written = handle_int(va_arg(args, int));
	else if (c == 'u')
		written = handle_uint(va_arg(args, unsigned int));
	else if (c == 'x')
		written = handle_lhex(va_arg(args, unsigned int));
	else if (c == 'X')
		written = handle_uhex(va_arg(args, unsigned int));
	else if (c == '%')
		written = handle_percent();
	return (written);
}

static int	write_str(const char *str, va_list args)
{
	int	i;
	int	slen;
	int	padding;
	int	written;

	i = 0;
	slen = ft_strlen(str);
	written = 0;
	while (i < slen)
	{
		if (str[i] == '%')
		{
			padding = handle_conv(str[i + 1], args);
			written += padding;
			if (padding >= 0)
			{
				i += 2;
				continue ;
			}
		}
		write(1, &str[i], 1);
		written++;
		i++;
	}
	return (written);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		written;

	if (!str)
		return (0);
	written = 0;
	va_start(args, str);
	written = write_str(str, args);
	va_end(args);
	return (written);
}
