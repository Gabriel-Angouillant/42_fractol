/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:22:24 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/09 18:41:44 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	complex_calc(t_cplx *z, t_cplx c, t_fractal *ftl)
{
	double	tmp;
	int		iter;

	iter = ftl->stg.max_iter;
	while (iter && sqrt(z->r * z->r + z->i * z->i) < 128)
	{
		if (ftl->current_fract == init_bship)
		{
			z->r = fabs(z->r);
			z->i = fabs(z->i);
		}
		tmp = z->r;
		z->r = z->r * z->r - z->i * z->i + c.r;
		z->i = tmp * z->i * 2 + c.i;
		iter--;
	}
	if (iter == 0)
		return (0);
	else
		return (iter);
}

void	render(t_fractal *ftl, void (*init_set)())
{
	double	x;
	double	y;
	int		iter;

	x = 0;
	while (x < W_WIDTH)
	{
		y = 0;
		while (y < W_HEIGHT)
		{
			init_set(&ftl->clc, x, y);
			iter = complex_calc(&ftl->clc.z, ftl->clc.c, ftl);
			draw_pixel(ftl, x, y, iter);
			y += ftl->stg.pixel_step;
		}
		x += ftl->stg.pixel_step;
	}
}

void	init_mandelbrot(t_calc *clc, double x, double y)
{
	float	scale;

	scale = (float)W_WIDTH / W_HEIGHT;
	clc->z.r = 0;
	clc->z.i = 0;
	clc->c.r = clc->xm + map((float [2]){0, W_WIDTH}, \
	(float [2]){-clc->range * scale, clc->range * scale}, x);
	clc->c.i = clc->ym + map((float [2]){0, W_HEIGHT}, \
	(float [2]){-clc->range, clc->range}, y);
}

void	init_bship(t_calc *clc, double x, double y)
{
	float	scale;

	scale = (float)W_WIDTH / W_HEIGHT;
	clc->z.r = 0;
	clc->z.i = 0;
	clc->c.r = clc->xm + map((float [2]){0, W_WIDTH}, \
	(float [2]){-clc->range * scale, clc->range * scale}, x);
	clc->c.i = clc->ym + map((float [2]){0, W_HEIGHT}, \
	(float [2]){-clc->range, clc->range}, y);
}

void	init_julia(t_calc *clc, double x, double y)
{
	float	scale;

	scale = (float)W_WIDTH / W_HEIGHT;
	clc->z.r = clc->xm + map((float [2]){0, W_WIDTH}, \
	(float [2]){-clc->range * scale, clc->range * scale}, x);
	clc->z.i = clc->ym + map((float [2]){0, W_HEIGHT}, \
	(float [2]){-clc->range, clc->range}, y);
}
