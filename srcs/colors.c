/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:23:42 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/11 17:25:24 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static uint32_t	rgb_to_hex(t_color rgb)
{
	uint32_t	c;

	c = ((255 & 0xff) << 24) + ((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) \
	+ (rgb.b & 0xff);
	return (c);
}

static int	rgb_lerp(t_color colour1, t_color colour2, float mod)
{
	return (rgb_to_hex((t_color){.r = lerp(colour1.r, colour2.r, mod),
			.g = lerp(colour1.g, colour2.g, mod),
			.b = lerp(colour1.b, colour2.b, mod)}));
}

static int	choose_colour(t_fractal ftl, int iter)
{
	double		log_zn;
	double		nu;
	double		iterf;
	t_palette	palette;

	palette = get_palette(abs(ftl.stg.colour));
	iterf = iter;
	if (iter == 0)
		return (0xFF000000);
	else if (ftl.stg.smoothing == 1)
	{
		iterf = ftl.stg.max_iter - iterf;
		log_zn = log((ftl.clc.z.r * ftl.clc.z.r) + \
		(ftl.clc.z.i * ftl.clc.z.i)) / 2;
		nu = log(log_zn / log(2)) / log(2);
		iterf += 1 - nu;
	}
	iterf = iter_transform(iterf, ftl.stg.transform);
	return (rgb_lerp(palette.colours[(int)floor(iterf) % palette.len]
			, palette.colours[((int)(floor(iterf) + 1) % palette.len)],
		fmod(iterf, 1)));
}

void	draw_pixel(t_fractal *ftl, int x, int y, int iter)
{
	int			colour;
	int			j;
	int			k;

	colour = choose_colour(*ftl, iter);
	if (ftl->stg.pixel_step == 1)
	{
		mlx_set_image_pixel(ftl->mlx.mlx, ftl->mlx.img, x, y, colour);
		return ;
	}
	j = 0;
	k = 0;
	while (j < ftl->stg.pixel_step && (x + j < W_WIDTH || x + k < W_HEIGHT))
	{
		k = 0;
		while (k < ftl->stg.pixel_step && (x + k < W_HEIGHT || x + j < W_WIDTH))
		{
			mlx_set_image_pixel(ftl->mlx.mlx, ftl->mlx.img, x + j, y + k, \
			colour);
			k++;
		}
		j++;
	}
}
