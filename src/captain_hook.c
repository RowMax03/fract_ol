/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   captain_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:50:10 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 21:07:55 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	change_color(t_data *data)
{
	if (data->r < 2)
	{
		if (data->g < 2)
		{
			if (data->b < 2)
				return (data->b++);
			return (data->g++);
		}
		data->g = 0;
		data->b = 0;
		return (data->r++);
	}
	data->r = 0;
	return (1);
}

void	ft_hook(void *param)
{
	t_data		*data;
	mlx_image_t	*frac_img;

	data = param;
	frac_img = data->win_ptr;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx_ptr);
	if (mlx_is_mouse_down(data->mlx_ptr, MLX_MOUSE_BUTTON_LEFT))
	{
		change_color(data);
		draw_fractal(data);
	}
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_UP))
		move_up(data);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_DOWN))
		move_down(data);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_LEFT))
		move_left(data);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
		move_right(data);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = param;
	if (ydelta > 0)
	{
		zoom_in(data);
		draw_fractal(data);
	}
	else if (ydelta < 0)
	{
		zoom_out(data);
		draw_fractal(data);
	}
	if (xdelta < 0)
		move_left(data);
	else if (xdelta > 0)
		move_right(data);
}

void	resize_window(int32_t width, int32_t height, void *param)
{
	t_data	*data;

	data = param;
	mlx_resize_image(data->win_ptr, width, height);
	data->dim.width = width;
	data->dim.height = height;
	data->max.imag = data->min.imag
		+ (data->max.real - data->min.real)
		* data->dim.height / data->dim.width;
	draw_fractal(data);
}
