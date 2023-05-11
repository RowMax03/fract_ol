/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:25:22 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/11 22:58:23 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define TITLE "Fractol"
# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct	s_complex
{
	double	real;
	double	imag;
}				t_complex;

typedef struct	s_data
{
	int		r;
	int		g;
	int		b;
	void	*mlx_ptr;
	void	*win_ptr;
	double	scale;
	t_complex	min;
	t_complex	max;
	//int		(*fractal_func)(t_complex, t_data*, int, int);
}				t_data;

int			mandelbrot(t_data *data, int x, int y);
int			julia(t_complex z, t_complex c);
void		draw_fractal(t_data *data);
void		put_pixel_to_image(int x, int y, int color, void *img_ptr);
void		clear_image(void *img_ptr);
void		draw_line(int x0, int y0, int x1, int y1, int color, void *img_ptr);
int 		key_hook(struct mlx_key_data *key_data, void *param);
int			mouse_hook(int button, int x, int y, void *param);
uint32_t	generate_colors(int iterations, int max_iterations, t_data *data);

#endif
