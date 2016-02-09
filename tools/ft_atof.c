/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 17:54:55 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/06 17:54:56 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "tools.h"

float		ft_atof(char *str)
{
	float	result;
	float	mul;
	int		i;

	i = 0;
	if (str[0] == '-')
		++i;
	mul = pow(10, ft_strlen(str) - (1 + i));
	result = 0;
	while (str[i])
	{
		result += mul * (str[i] - '0');
		mul /= 10;
		++i;
	}
	if (str[0] == '-')
		result = -result;
	return (result);
}
