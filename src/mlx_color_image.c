/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 23:04:11 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/13 23:04:11 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "mlx_color_image.h"
#include "defines.h"
#include "struct.h"

void		full_image(t_global *g, int x)
{
	int		i;

	i = 0;
	while (i < HEIGHT)
	{
		if (i < g->val.draw_start)
			put_color_image(g, x, i, 0xfd9600);
		else if (i >= g->val.draw_start && i < g->val.draw_end)
			put_color_image(g, x, i, g->val.color);
		else
			put_color_image(g, x, i, 0x5ca028);
		i++;
	}
}

void		put_color_image(t_global *g, int x, int i, int color)
{
	g->mlx.color = mlx_get_color_value(g->mlx.mlx_p, color);
	g->mlx.data[(x * g->mlx.bpp / 8) + i * g->mlx.sl] =
		(g->mlx.color & 0xFF0000) >> 16;
	g->mlx.data[(x * g->mlx.bpp / 8) + i * g->mlx.sl + 1] =
		(g->mlx.color & 0xFF00) >> 8;
	g->mlx.data[(x * g->mlx.bpp / 8) + i * g->mlx.sl + 2] =
		(g->mlx.color & 0xFF) >> 0;
}
