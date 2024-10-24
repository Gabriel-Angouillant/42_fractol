/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:22:08 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/09 18:47:24 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	reset_fractal(t_fractal *ftl)
{
	ftl->clc.range = 2;
	ftl->clc.xm = 0;
	ftl->clc.ym = 0;
	ftl->clc.c.r = -0.5;
	ftl->clc.c.i = 0.5;
}

void	julia_selector(t_fractal *ftl, int key)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(ftl->mlx.mlx, &x, &y);
	if (key == 43)
	{
		ftl->clc.c.r = map((float [2]){0, W_WIDTH}, (float [2]){-1.5, 1.5}, x);
		ftl->clc.c.i = map((float [2]){0, W_HEIGHT}, (float [2]){-1.5, 1.5}, y);
	}
	else if (key == 20 && ftl->clc.c.r < 1.35)
		ftl->clc.c.r += 0.01;
	else if (key == 4 && ftl->clc.c.r > -1.35)
		ftl->clc.c.r -= 0.01;
	else if (key == 26 && ftl->clc.c.i < 1.35)
		ftl->clc.c.i += 0.01;
	else if (key == 22 && ftl->clc.c.i > -1.35)
		ftl->clc.c.i -= 0.01;
	render(ftl, ftl->current_fract);
}

void	pixelise(int key, t_fractal *ftl)
{
	if (key == 45 && ftl->stg.pixel_step > 1)
		ftl->stg.pixel_step -= 1;
	else if (key == 46 && ftl->stg.pixel_step < 6)
		ftl->stg.pixel_step += 1;
	render(ftl, ftl->current_fract);
}

void	save_pos(t_fractal *ftl)
{
	static double	range = 255;
	static double	xm;
	static double	ym;
	static t_cplx	c;
	static void		*current_fract;

	if (range == 255)
	{
		range = ftl->clc.range;
		xm = ftl->clc.xm;
		ym = ftl->clc.ym;
		c = ftl->clc.c;
		current_fract = ftl->current_fract;
		return ;
	}
	ftl->clc.range = range;
	ftl->clc.xm = xm;
	ftl->clc.ym = ym;
	ftl->clc.c = c;
	ftl->current_fract = current_fract;
	range = 255;
	render(ftl, ftl->current_fract);
}
