/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:22:28 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/09 18:36:22 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

float	lerp(float v0, float v1, float t)
{
	return ((1 - t) * v0 + t * v1);
}

double	map(float r1[2], float r2[2], float val)
{
	float	newval;

	newval = (val - r1[0]) / (r1[1] - r1[0]) * (r2[1] - r2[0]) + r2[0];
	if (r2[0] < r2[1])
		return (fmax(fmin(newval, r2[1]), r2[0]));
	return (fmax(fmin(newval, r2[0]), r2[1]));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	i = 0;
	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	while (ucs1[i] && ucs2[i] && ucs1[i] == ucs2[i])
		i++;
	return (ucs1[i] - ucs2[i]);
}
