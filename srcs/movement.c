/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:29:01 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/09 18:46:42 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move(int key, t_fractal *ftl)
{
	if (key == 79)
		ftl->clc.xm += 0.1 * ftl->clc.range;
	else if (key == 80)
		ftl->clc.xm -= 0.1 * ftl->clc.range;
	else if (key == 81)
		ftl->clc.ym += 0.1 * ftl->clc.range;
	else if (key == 82)
		ftl->clc.ym -= 0.1 * ftl->clc.range;
	render(ftl, ftl->current_fract);
}

void	zoom(t_fractal *ftl)
{
	int	r_xm;
	int	r_ym;

	mlx_mouse_get_pos(ftl->mlx.mlx, &r_xm, &r_ym);
	ftl->clc.range *= 0.75;
	ftl->clc.xm += map((float [2]){0, W_WIDTH}, \
	(float [2]){-ftl->clc.range, ftl->clc.range}, r_xm) * 0.5;
	ftl->clc.ym += map((float [2]){0, W_HEIGHT}, \
	(float [2]){-ftl->clc.range, ftl->clc.range}, r_ym) * 0.5;
	render(ftl, ftl->current_fract);
}

void	unzoom(t_fractal *ftl)
{
	int	r_xm;
	int	r_ym;

	mlx_mouse_get_pos(ftl->mlx.mlx, &r_xm, &r_ym);
	ftl->clc.range *= 1.5;
	render(ftl, ftl->current_fract);
}
