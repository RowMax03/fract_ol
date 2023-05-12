/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:25:17 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 21:09:30 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static uint32_t	to_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return ((uint32_t)(red << 24 | green << 16 | blue << 8 | 0xFF));
}

static uint8_t	get_red(double hue, double saturation, double lightness)
{
	double	chroma;
	double	x;
	double	m;
	double	red;

	chroma = (1.0 - fabs(2 * lightness - 1.0)) * saturation;
	x = chroma * (1.0 - fabs(fmod(hue / 60.0, 2) - 1.0));
	m = lightness - chroma / 2.0;
	red = 0.0;
	if (hue >= 0 && hue < 60)
		red = chroma;
	else if (hue >= 60 && hue < 120)
		red = x;
	else if (hue >= 240 && hue < 300)
		red = x;
	else if (hue >= 300 && hue < 360)
		red = chroma;
	return ((uint8_t)((red + m) * 255));
}

static uint8_t	get_green(double hue, double saturation, double lightness)
{
	double	chroma;
	double	x;
	double	m;
	double	green;

	chroma = (1.0 - fabs(2 * lightness - 1.0)) * saturation;
	x = chroma * (1.0 - fabs(fmod(hue / 60.0, 2) - 1.0));
	m = lightness - chroma / 2.0;
	green = 0.0;
	if (hue >= 60 && hue < 180)
		green = chroma;
	else if (hue >= 180 && hue < 240)
		green = x;
	return ((uint8_t)((green + m) * 255));
}

static uint8_t	get_blue(double hue, double saturation, double lightness)
{
	double	chroma;
	double	x;
	double	m;
	double	blue;

	chroma = (1.0 - fabs(2 * lightness - 1.0)) * saturation;
	x = chroma * (1.0 - fabs(fmod(hue / 60.0, 2) - 1.0));
	m = lightness - chroma / 2.0;
	blue = 0.0;
	if (hue >= 0 && hue < 60)
		blue = x;
	else if (hue >= 120 && hue < 240)
		blue = chroma;
	else if (hue >= 240 && hue < 360)
		blue = x;
	return ((uint8_t)((blue + m) * 255));
}

uint32_t	generate_colors(int iterations, int max_iterations, t_data *data)
{
	double	hue;
	double	saturation;
	double	lightness;
	uint8_t	colors[3];

	hue = (double)iterations / (double)max_iterations * 360.0;
	saturation = 1.0;
	lightness = 0.5;
	colors[0] = get_red(hue, saturation, lightness);
	colors[1] = get_green(hue, saturation, lightness);
	colors[1] = get_blue(hue, saturation, lightness);
	return (to_rgb(colors[data->r], colors[data->g], colors[data->b]));
}
