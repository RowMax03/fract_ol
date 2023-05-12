/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_left_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:06:21 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 20:25:08 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	move_up(t_data *data)
{
	double	mult;

	mult = data->max.imag - data->min.imag;
	data->min.imag -= mult / 50;
	data->max.imag -= mult / 50;
	draw_fractal(data);
}

void	move_down(t_data *data)
{
	double	mult;

	mult = data->max.imag - data->min.imag;
	data->min.imag += mult / 50;
	data->max.imag += mult / 50;
	draw_fractal(data);
}

void	move_left(t_data *data)
{
	double	mult;

	mult = data->max.real - data->min.real;
	data->min.real -= mult / 50;
	data->max.real -= mult / 50;
	draw_fractal(data);
}

void	move_right(t_data *data)
{
	double	mult;

	mult = data->max.real - data->min.real;
	data->min.real += mult / 50;
	data->max.real += mult / 50;
	draw_fractal(data);
}
