/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:25:34 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/09 18:48:19 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

float	iter_transform(float iter, enum e_transform transform)
{
	if (transform == T_LIN)
		return (iter);
	if (transform == T_SQRT)
		return (sqrt(fabs(iter)));
	if (transform == T_LOG)
		return (log(fabs(iter)));
	if (transform == T_SQR)
		return (iter * iter);
	return (0);
}

t_palette	get_palette(int i)
{
	t_palette	palettes[5];

	palettes[0] = (t_palette){.colours = {{.r = 255, .g = 161, .b = 161},
	{.r = 255, .g = 195, .b = 139},
	{.r = 250, .g = 251, .b = 163},
	{.r = 207, .g = 255, .b = 162},
	{.r = 152, .g = 255, .b = 246}}, 5};
	palettes[1] = (t_palette){.colours = {{.r = 198, .g = 20, .b = 7},
	{.r = 244, .g = 183, .b = 0},
	{.r = 35, .g = 32, .b = 32},
	{.r = 255, .g = 130, .b = 0},
	{.r = 102, .g = 0, .b = 0}}, 5};
	palettes[2] = (t_palette){.colours = {{.r = 255, .g = 0, .b = 255},
	{.r = 255, .g = 255, .b = 0},
	{.r = 0, .g = 0, .b = 255},
	{.r = 0, .g = 255, .b = 0},
	{.r = 255, .g = 0, .b = 0}}, 5};
	palettes[3] = (t_palette){.colours = {{.r = 255, .g = 255, .b = 255},
	{.r = 0, .g = 0, .b = 0}}, 2};
	palettes[4] = (t_palette){.colours = {{.r = 216, .g = 178, .b = 255},
	{.r = 178, .g = 102, .b = 255},
	{.r = 69, .g = 0, .b = 226},
	{.r = 49, .g = 0, .b = 162},
	{.r = 76, .g = 0, .b = 153}}, 5};
	return (palettes[i % 5]);
}
