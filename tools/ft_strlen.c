/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:18:41 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/03 18:18:42 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		ft_putstr_e("Error with ft_strlen !\n");
		exit(-1);
	}
	while (str[i])
		i++;
	return (i);
}
