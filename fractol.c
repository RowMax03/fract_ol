/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:23:30 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/11 22:58:50 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int iter;
	t_complex z;

	x = -1;
	z.imag = 0;
	z.real = 0;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			iter = mandelbrot(data, x, y);
			color = generate_colors(iter, MAX_ITER, data);
			mlx_put_pixel(data->win_ptr, x, y, color);
		}
	}
	//mlx_image_to_window(data->mlx_ptr, data->win_ptr, 0, 0);
}

// int key_hook(struct mlx_key_data *key_data, void *param)
// {
//     int keycode = *((int *)key_data->key);
//     t_data *data = (t_data *)param;

//     if (keycode == KEY_ESC)
//         exit(0);
//     else if (keycode == KEY_SPACE)
//         data->fractal_func = (data->fractal_func == mandelbrot) ? julia : mandelbrot;
//     else if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
//     {
//         double dx = (keycode == KEY_LEFT) ? -0.1 : (keycode == KEY_RIGHT) ? 0.1 : 0;
//         double dy = (keycode == KEY_UP) ? -0.1 : (keycode == KEY_DOWN) ? 0.1 : 0;
//         double new_real = data->c.real + dx;
//         double new_imag = data->c.imag + dy;

//         if (data->fractal_func == mandelbrot)
//         {
//             double new_scale = data->scale * pow(1.1, dy);
//             data->scale = (new_scale > 0.001) ? new_scale : data->scale;
//         }

//         data->c = (t_complex){ new_real, new_imag };
//     }
//     draw_fractal(data);
//     return (0);
// }

static	void	ft_hook(void *param)
{
	t_data		*data;
	mlx_image_t	*frac_img;

	data = param;
	frac_img = data->win_ptr;

	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx_ptr);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_UP))
		frac_img->instances[0].y -= 5;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_DOWN))
		frac_img->instances[0].y += 5;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_LEFT))
		frac_img->instances[0].x -= 5;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
		frac_img->instances[0].x += 5;
	//printf("y: %d x: %d\n", fdf_img->instances[0].y, fdf_img->instances[0].x);
}



// void mouse_hook(int button, int x, int y, void *param)
// {
//   t_data *data = (t_data *)param;
  
//   if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
//   {
//     double new_scale = data->scale * pow(1.1, (button == MOUSE_SCROLL_UP) ? 1 : -1);
//     data->scale = (new_scale > 0.001) ? new_scale : data->scale;
//     double new_real = data->c.real + (x - WIDTH / 2) * (4.0 / WIDTH) / data->scale;
//     double new_imag = data->c.imag + (y - HEIGHT / 2) * (4.0 / HEIGHT) / data->scale;
//     data->c = (t_complex){ new_real, new_imag };
//     draw_fractal(data->c, data->fractal_func, data->mlx_ptr, data->win_ptr);
//   }
// }

t_data *init_data(void *mlx_ptr, void *win_ptr)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
    {
        perror("Error: failed to allocate memory for t_data");
        exit(EXIT_FAILURE);
    }
	data->mlx_ptr = mlx_ptr;
	data->win_ptr = win_ptr;
	data->scale = 1;
	data->min.real = -2;
	data->min.imag = -1.02;
	data->max.real = 1.0;
	data->max.imag = -1;
	data->max.imag = data->min.imag
		+ (data->max.real - data->min.real)
		* HEIGHT / WIDTH;
	//data->fractal_func = mandelbrot;
	data->r = 0;
	data->g = 1;
	data->b = 2;
	return (data);
}

int main()
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*win_ptr;
	t_data		*data;

	mlx_ptr = mlx_init(WIDTH, HEIGHT, TITLE, true);
	win_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	data = init_data(mlx_ptr, win_ptr);
	mlx_image_to_window(data->mlx_ptr, data->win_ptr, 0, 0);
	mlx_loop_hook(mlx_ptr, &ft_hook, &data);
	// Draw the Mandelbrot set
	draw_fractal(data);
	mlx_loop(mlx_ptr);
	mlx_delete_image(data->mlx_ptr, data->win_ptr);
	mlx_terminate(data->mlx_ptr);
	return (EXIT_SUCCESS);
}