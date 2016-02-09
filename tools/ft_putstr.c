/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:20:29 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/03 18:20:30 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "tools.h"

void		ft_putstr(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
}

void		ft_putendl(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
	ft_putchar('\n');
}

void		ft_putstr_e(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(2, str, len);
}
