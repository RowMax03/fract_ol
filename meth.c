/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meth.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:48:36 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 13:32:02 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	mandelbrot(t_complex z, t_data *data, int x, int y)
// {
// 	int			i;
// 	t_complex	tmp;
// 	double		zr;
// 	double		zi;

// 	z.real = 0;
// 	zr = (double)x + data->min.real
// 			* (data->max.real - data->min.real) / WIDTH;
// 	z.imag = 0;
// 	zi = (double)y + data->min.imag
// 			* (data->max.imag - data->min.imag) / HEIGHT;
// 	i = -1;
// 	while (++i < MAX_ITER)
// 	{
// 		if ((z.real * z.real + z.imag * z.imag) > 4.0)
// 			return (i);
// 		tmp.real = z.real;
// 		tmp.imag = z.imag;
// 		z.real = tmp.real * tmp.real - tmp.imag * tmp.imag + zr;
// 		z.imag = 2 * tmp.real * tmp.imag + zi;
// 	}
// 	return (i);
// }

int mandelbrot(t_data *data, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	tmp;

	z.real = 0;
	z.imag = 0;
	double zr = (double)x * (data->max.real - data->min.real) / WIDTH + data->min.real;
	double zi = (double)y * (data->max.imag - data->min.imag) / HEIGHT + data->min.imag;

	i = 0;
	while (i < MAX_ITER && (z.real * z.real + z.imag * z.imag) <= 4.0)
	{
		tmp.real = z.real;
		tmp.imag = z.imag;
		z.real = tmp.real * tmp.real - tmp.imag * tmp.imag + zr;
		z.imag = 2 * tmp.real * tmp.imag + zi;
		i++;
	}
    return i;
}

int	julia(t_complex z, t_complex c)
{
	int			i;
	t_complex	tmp;

	i = -1;
	while (++i < MAX_ITER && (z.real * z.real + z.imag * z.imag) < 4)
	{
		tmp.real = z.real;
		tmp.imag = z.imag;
		z.real = tmp.real * tmp.real - tmp.imag * tmp.imag + c.real;
		z.imag = 2 * tmp.real * tmp.imag + c.imag;
	}
	return (i);
}
