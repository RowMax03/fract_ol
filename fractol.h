/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:25:22 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 21:11:51 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "includes/libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define TITLE "Fractol"
# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

typedef struct s_complex
{
	double	real;
	double	imag;
}				t_complex;

typedef struct s_dim
{
	int	width;
	int	height;
}				t_dim;

typedef struct s_data
{
	int			r;
	int			g;
	int			b;
	void		*mlx_ptr;
	void		*win_ptr;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_dim		dim;
	int			(*fractal_func)(struct s_data*, int, int);
}				t_data;

//fractal sets
int			mandelbrot(t_data *data, int x, int y);
int			julia(t_data *data, int x, int y);
int			dragon_curve(t_data *data, int x, int y);
int			feigenbaum(t_data *data, int x, int y);
int			dart(t_data *data, int x, int y);

//fractal generation
void		draw_fractal(t_data *data);
uint32_t	generate_colors(int iterations, int max_iterations, t_data *data);
void		input_fractal(int argc, char **argv, t_data *data);

//movment
void		zoom_in(t_data *data);
void		zoom_out(t_data *data);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

//hooks
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		ft_hook(void *param);
void		resize_window(int width, int height, void *param);

#endif