/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:43:41 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 20:18:33 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void	print_er(t_data *data)
{
	ft_printf("No correct Fractal defined. Available fractals: ");
	ft_printf("Mandelbrot, Julia, Dart\n or \n");
	ft_printf("Julia <real> <imaginary> \n");
	free(data);
	exit(EXIT_FAILURE);
}

void	input_fractal(int argc, char **argv, t_data *data)
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "Mandelbrot", 11))
			data->fractal_func = &mandelbrot;
		else if (!ft_strncmp(argv[1], "Julia", 11))
			data->fractal_func = &julia;
		else if (!ft_strncmp(argv[1], "Dart", 11))
			data->fractal_func = &dart;
		else
			print_er(data);
	}
	else if (argc == 4 && ft_isnum(argv[2]) && ft_isnum(argv[3]))
	{
		if (ft_strncmp("Julia", argv[1], 6) == 0)
		{
			data->c.real = ft_atod(argv[2]);
			data->c.imag = ft_atod(argv[3]);
			data->fractal_func = &julia;
		}
	}
	else
		print_er(data);
}
