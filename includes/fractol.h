/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:10:37 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/09 18:57:59 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MacroLibX/includes/mlx.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# ifndef W_WIDTH
#  define W_WIDTH 1080
# endif

# ifndef W_HEIGHT
#  define W_HEIGHT 720
# endif

enum e_transform
{
	T_LIN,
	T_SQRT,
	T_LOG,
	T_SQR,
};

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color;

typedef struct s_palette
{
	t_color	colours[10];
	int		len;
}	t_palette;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_cplx;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct s_calc
{
	double	range;
	double	xm;
	double	ym;
	t_cplx	c;
	t_cplx	z;
}	t_calc;

typedef struct s_settings
{
	enum e_transform	transform;
	int					pixel_step;
	int					smoothing;
	int					colour;
	int					max_iter;
}	t_settings;

typedef struct s_fractal
{
	void		*current_fract;
	t_mlx		mlx;
	t_calc		clc;
	t_settings	stg;
}	t_fractal;

double		map(float r1[2], float r2[2], float val);
float		lerp(float v0, float v1, float t);
void		init_mandelbrot(t_calc *clc, double x, double y);
void		init_bship(t_calc *clc, double x, double y);
void		init_julia(t_calc *clc, double x, double y);
void		render(t_fractal *ftl, void (*init_set)());
void		draw_pixel(t_fractal *ftl, int x, int y, int iter);
void		reset_fractal(t_fractal *ftl);
void		julia_selector(t_fractal *ftl, int key);
void		pixelise(int key, t_fractal *ftl);
void		save_pos(t_fractal *ftl);
void		move(int key, t_fractal *ftl);
void		zoom(t_fractal *ftl);
void		unzoom(t_fractal *ftl);
int			mouse_hook(int key, void *ftl);
int			key_hook(int key, void *ftl);
void		create_win(t_mlx *mlx);
void		clear_win(t_fractal	*ftl);
int			ft_strcmp(const char *s1, const char *s2);
t_palette	get_palette(int i);
float		iter_transform(float iter, enum e_transform transform);
int			window_hook(int key, void *ftl);
int			wheel_hook(int key, void *ftl);
void		select_fractal(char **argv, t_fractal *ftl);
void		error_check(int argc, char **argv);

#endif
