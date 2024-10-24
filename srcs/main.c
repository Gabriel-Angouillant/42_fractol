/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:24:21 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/09 18:20:01 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_fractal	ftl_init(void)
{
	t_fractal	ftl;
	t_settings	stg;
	t_calc		clc;

	create_win(&ftl.mlx);
	stg.transform = T_SQRT;
	stg.pixel_step = 1;
	stg.smoothing = 1;
	stg.colour = 0;
	stg.max_iter = 100;
	clc.range = 2;
	clc.xm = 0;
	clc.ym = 0;
	clc.c.r = -0.5;
	clc.c.i = 0.5;
	ftl.stg = stg;
	ftl.clc = clc;
	return (ftl);
}

int	main(int argc, char **argv)
{
	t_fractal	ftl;

	error_check(argc, argv);
	ftl = ftl_init();
	select_fractal(argv, &ftl);
	mlx_on_event(ftl.mlx.mlx, ftl.mlx.win, MLX_KEYUP, key_hook, &ftl);
	mlx_on_event(ftl.mlx.mlx, ftl.mlx.win, MLX_MOUSEUP, mouse_hook, &ftl);
	mlx_on_event(ftl.mlx.mlx, ftl.mlx.win, MLX_WINDOW_EVENT, window_hook, &ftl);
	mlx_on_event(ftl.mlx.mlx, ftl.mlx.win, MLX_MOUSEWHEEL, wheel_hook, &ftl);
	mlx_loop(ftl.mlx.mlx);
	clear_win(&ftl);
	return (0);
}
