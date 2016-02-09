/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:20:22 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/03 18:20:24 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#include "tools.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putchar_e(char c)
{
	write(2, &c, 1);
}
