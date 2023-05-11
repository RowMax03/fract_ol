/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:25:17 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/11 20:32:18 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

uint32_t	to_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return ((uint32_t)(red << 24 | green << 16 | blue << 8 | 0xFF));
}

uint32_t	generate_colors(int iterations, int max_iterations, t_data *data)
{
	double	ratio;
	double	ratio_reciprocal;
	uint8_t	colors[3];

	ratio = (double)iterations / (double)max_iterations;
	ratio_reciprocal = 1.0 - ratio;
	colors[0] = 9 * (ratio * ratio * ratio) * ratio_reciprocal * 255;
	colors[1] = 15 * (ratio * ratio)
		* (ratio_reciprocal * ratio_reciprocal) * 255;
	colors[2] = 9 * ratio
		* (ratio_reciprocal * ratio_reciprocal * ratio_reciprocal) * 255;
	return (to_rgb(colors[data->r], colors[data->g], colors[data->b]));
}

int	change_color(t_data *data)
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