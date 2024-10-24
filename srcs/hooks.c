/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:25:10 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/09 18:49:20 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	window_hook(int key, void *ftl)
{
	if (key == 0)
		clear_win(ftl);
	return (0);
}

int	mouse_hook(int key, void *ftl)
{
	if (key == 1)
		zoom(ftl);
	if (key == 3)
		unzoom(ftl);
	return (0);
}

int	wheel_hook(int key, void *ftl)
{
	if (key == 1)
		zoom(ftl);
	if (key == 2)
		unzoom(ftl);
	return (0);
}

static int	next_key_hook(int key, t_fractal *ftl)
{
	if (key == 229 || key == 228 || key == 56 || key == 13 || key == 14)
	{
		if (key == 229)
			ftl->stg.transform = (ftl->stg.transform + 1) % 4;
		else if (key == 228)
			ftl->stg.colour = (ftl->stg.colour + 1) % 5;
		else if (key == 56)
			ftl->stg.smoothing = (ftl->stg.smoothing + 1) % 2;
		else if (key == 13 && ftl->stg.max_iter > 80)
			ftl->stg.max_iter -= 50;
		else if (key == 14 && ftl->stg.max_iter < 500)
			ftl->stg.max_iter += 50;
		render(ftl, ftl->current_fract);
	}
	else if ((key == 20 || key == 4 || key == 26 || key == 22 || key == 43)
		&& ftl->current_fract == init_julia)
		julia_selector(ftl, key);
	return (0);
}

int	key_hook(int key, void *ftl)
{
	t_fractal	*ftlbis;

	ftlbis = (t_fractal *)ftl;
	if (key == 41)
		clear_win(ftl);
	else if (key == 45 || key == 46)
		pixelise(key, ftlbis);
	else if (key >= 79 && key <= 82)
		move(key, ftlbis);
	else if (key == 44)
		save_pos(ftlbis);
	else if (key == 21 || (key >= 30 && key <= 32))
	{
		reset_fractal(ftlbis);
		if (key == 30)
			ftlbis->current_fract = init_mandelbrot;
		else if (key == 31)
			ftlbis->current_fract = init_julia;
		else if (key == 32)
			ftlbis->current_fract = init_bship;
		render(ftlbis, ftlbis->current_fract);
	}
	else
		next_key_hook(key, ftlbis);
	return (0);
}
