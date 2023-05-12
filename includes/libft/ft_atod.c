/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:42:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/12 19:18:59 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <ctype.h>

double	ft_atod(const char *str)
{
	int		sign;
	double	result;
	double	decimal;
	int		has_decimal;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	result = 0.0;
	decimal = 1.0;
	has_decimal = 0;
	while ((*str >= '0' && *str <= '9') || (*str == '.' && !has_decimal))
	{
		if (*str == '.')
			has_decimal = 1;
		else if (!has_decimal)
			result = result * 10.0 + (*str - '0');
		else
			result += decimal * (*str - '0') * 0.1;
		str++;
	}
	return (result * sign);
}

//				if (!ft_isdigit(str[i + 1]))
					//return (toi * checkneg(str));