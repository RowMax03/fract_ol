/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   captain_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:50:10 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 13:55:01 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_data	*data;

	data = param;
	// Simple up or down detection.
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
	
	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}