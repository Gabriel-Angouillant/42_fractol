/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:50:01 by gangouil          #+#    #+#             */
/*   Updated: 2023/12/21 14:50:13 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_printf(const char *str, ...);
int		ft_putnbr_base(uint64_t n, int base, char *table, int *written);
int		handle_int(int n);
int		handle_uint(unsigned int n);
int		handle_ptr(void *ptr);
int		handle_lhex(unsigned int n);
int		handle_uhex(unsigned int n);
int		handle_char(unsigned int c);
int		handle_str(char *c);
int		handle_percent(void);
int		ft_strlen(const char *str);

#endif
