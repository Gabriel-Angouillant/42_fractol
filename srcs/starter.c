/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:42:10 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/09 18:48:37 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_args(void)
{
	ft_printf("\033[1;32m[Welcome to Fract-ol]\n\n\
Execute:\033[0m ./fractol [fractal]\n\033[1;32mAvailable fractals:\033[0m\
 Mandelbrot, Julia, BShip\n\n\033[1;32mUsage: \033[1;37m\n\n\
Move:\033[0m Arrow keys	\033[1;37mZoom: \033[0mLeft/Right click\n\033[1;37m\
Reset:\033[0m R		\033[1;37mSave/Load: \033[0mSpace\n\033[1;37m\n\
-/+ Iters:\033[0m J/K		\033[1;37m-/+ Pixels: \033[0m-/+\n\033[1;37m\
Julia Start:\033[0m A/Q/S/W	\033[1;37mJulia Selector: \033[0mTab\n\n\
\033[1;37mColor:\033[0m Right Ctrl	\033[1;37mStyle: \033[0m\
Right Shift\n\033[1;37mOff/On Smoothing:\033[0m ?	\033[1;37mChange fractal\
:\033[0m 1/2/3\n");
}

void	error_check(int argc, char **argv)
{
	write(2, "\033[1;31m", 7);
	if (W_WIDTH < 10 || W_HEIGHT < 10 || argc != 2)
	{
		if (W_WIDTH < 10 || W_HEIGHT < 10)
			write(2, "\nError:\033[0m\033[31m Window is too small\n\n", 39);
		if (argc != 2)
			write(2, "\nError:\033[0m\033[31m Invalid number of arguments\n\n\
			", 46);
		print_args();
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "Mandelbrot") != 0
		&& ft_strcmp(argv[1], "Julia") != 0
		&& ft_strcmp(argv[1], "BShip") != 0)
	{
		write(2, "\nError:\033[0m\033[31m Fractal doesn't exist\n\n", 41);
		print_args();
		exit(EXIT_FAILURE);
	}
	print_args();
}

void	select_fractal(char **argv, t_fractal *ftl)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		ftl->current_fract = init_mandelbrot;
		render(ftl, init_mandelbrot);
	}
	if (ft_strcmp(argv[1], "Julia") == 0)
	{
		ftl->current_fract = init_julia;
		render(ftl, init_julia);
	}
	if (ft_strcmp(argv[1], "BShip") == 0)
	{
		ftl->current_fract = init_bship;
		render(ftl, init_bship);
	}
}
