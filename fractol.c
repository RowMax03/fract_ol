/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:23:30 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 20:25:01 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_data *data)
{
	int			x;
	int			y;
	int			color;
	int			iter;

	x = -1;
	while (++x < data->dim.width)
	{
		y = -1;
		while (++y < data->dim.height)
		{
			iter = data->fractal_func(data, x, y);
			color = generate_colors(iter, MAX_ITER, data);
			mlx_put_pixel(data->win_ptr, x, y, color);
		}
	}
}

t_data	*init_data(void *mlx_ptr, void *win_ptr)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("Error: failed to allocate memory for t_data");
		exit(EXIT_FAILURE);
	}
	data->mlx_ptr = mlx_ptr;
	data->win_ptr = win_ptr;
	data->min.real = -2;
	data->min.imag = -1.02;
	data->max.real = 1.0;
	data->max.imag = -1;
	data->c.real = -0.4;
	data->c.imag = 0.6;
	data->dim.height = HEIGHT;
	data->dim.width = WIDTH;
	data->max.imag = data->min.imag
		+ (data->max.real - data->min.real)
		* data->dim.height / data->dim.width;
	data->r = 0;
	data->g = 1;
	data->b = 2;
	return (data);
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*win_ptr;
	t_data		*data;

	mlx_ptr = mlx_init(WIDTH, HEIGHT, TITLE, true);
	win_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	data = init_data(mlx_ptr, win_ptr);
	mlx_image_to_window(data->mlx_ptr, data->win_ptr, 0, 0);
	mlx_loop_hook(mlx_ptr, &ft_hook, data);
	mlx_scroll_hook(data->mlx_ptr, &my_scrollhook, data);
	input_fractal(argc, argv, data);
	draw_fractal(data);
	mlx_resize_hook(data->mlx_ptr, &resize_window, data);
	mlx_loop(mlx_ptr);
	mlx_delete_image(data->mlx_ptr, data->win_ptr);
	mlx_terminate(data->mlx_ptr);
	return (free(data), EXIT_SUCCESS);
}
