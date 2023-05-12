/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:34:14 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 13:58:32 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void zoom_in(t_data *data)
{
	int32_t	x;
	int32_t	y;
	double	xc;
	double	yc;

	mlx_get_mouse_pos(data->mlx_ptr, &x , &y);
	xc = (double)x * (data->max.real - data->min.real) / WIDTH + data->min.real;
	yc = (double)y * (data->max.imag - data->min.imag) / HEIGHT + data->min.imag;
	data->min.real = (data->min.real / 1.1) + xc - (xc / 1.1);
	data->min.imag = (data->min.imag / 1.1) + yc - (yc / 1.1);
	data->max.real = (data->max.real / 1.1) + xc - (xc / 1.1);
	data->max.imag = (data->max.imag / 1.1) + yc - (yc / 1.1);
}

void zoom_out(t_data *data)
{
	int32_t	x;
	int32_t	y;
	double	xc;
	double	yc;

	mlx_get_mouse_pos(data->mlx_ptr, &x , &y);
	xc = (double)x * (data->max.real - data->min.real) / WIDTH + data->min.real;
	yc = (double)y * (data->max.imag - data->min.imag) / HEIGHT + data->min.imag;
	data->min.real = (data->min.real * 1.1) + xc - (xc * 1.1);
	data->min.imag = (data->min.imag * 1.1) + yc - (yc * 1.1);
	data->max.real = (data->max.real * 1.1) + xc - (xc * 1.1);
	data->max.imag = (data->max.imag * 1.1) + yc - (yc * 1.1);
}