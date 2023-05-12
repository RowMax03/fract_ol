/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meth.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:48:36 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 19:47:21 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data *data, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	tmp;

	z.real = 0;
	z.imag = 0;
	data->c.real = (double)x * (data->max.real - data->min.real)
		/ data->dim.width + data->min.real;
	data->c.imag = (double)y * (data->max.imag - data->min.imag)
		/ data->dim.height + data->min.imag;
	i = 0;
	while (i < MAX_ITER && (z.real * z.real + z.imag * z.imag) <= 4.0)
	{
		tmp.real = z.real;
		tmp.imag = z.imag;
		z.real = tmp.real * tmp.real - tmp.imag * tmp.imag + data->c.real;
		z.imag = 2 * tmp.real * tmp.imag + data->c.imag;
		i++;
	}
	return (i);
}

int	julia(t_data *data, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	tmp;

	z.real = (double)x * (data->max.real - data->min.real)
		/ WIDTH + data->min.real;
	z.imag = (double)y * (data->max.imag - data->min.imag)
		/ HEIGHT + data->min.imag;
	i = 0;
	while (i < MAX_ITER && (z.real * z.real + z.imag * z.imag) <= 4.0)
	{
		tmp.real = z.real;
		tmp.imag = z.imag;
		z.real = tmp.real * tmp.real - tmp.imag * tmp.imag + data->c.real;
		z.imag = 2 * tmp.real * tmp.imag + data->c.imag;
		i++;
	}
	return (i);
}

int	dart(t_data *data, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;

	i = 0;
	z.real = 0;
	z.imag = 0;
	data->c.real = (double)x * (data->max.real - data->min.real)
		/ WIDTH + data->min.real;
	data->c.imag = (double)y * (data->max.imag - data->min.imag)
		/ HEIGHT + data->min.imag;
	while (i < MAX_ITER && (z.real * z.real + z.imag * z.imag) <= 4.0)
	{
		tmp = fabs(z.real * z.real - z.imag * z.imag + data->c.real);
		z.imag = 2 * z.real * z.imag + data->c.imag;
		z.real = tmp;
		i++;
	}
	return (i);
}
