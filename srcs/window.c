/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:09:38 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/11 17:26:13 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_win(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(EXIT_FAILURE);
	mlx_set_fps_goal(mlx->mlx, 50);
	mlx->win = mlx_new_window(mlx->mlx, W_WIDTH, W_HEIGHT, "fractol");
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->mlx);
		exit(EXIT_FAILURE);
	}
	mlx->img = mlx_new_image(mlx->mlx, W_WIDTH, W_HEIGHT);
	if (!mlx->img)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	clear_win(t_fractal *ftl)
{
	mlx_loop_end(ftl->mlx.mlx);
	mlx_destroy_image(ftl->mlx.mlx, ftl->mlx.img);
	mlx_destroy_window(ftl->mlx.mlx, ftl->mlx.win);
	mlx_destroy_display(ftl->mlx.mlx);
	exit(EXIT_SUCCESS);
}
