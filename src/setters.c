/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 22:32:04 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/13 22:32:04 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "setters.h"
#include "struct.h"
#include "mlx.h"

void	set_mlx(t_global *g)
{
	g->mlx.mlx_p = mlx_init();
	g->mlx.win_p = mlx_new_window(g->mlx.mlx_p, WIDTH, HEIGHT, TITLE);
	g->mlx.img_p = mlx_new_image(g->mlx.mlx_p, WIDTH, HEIGHT);
	g->mlx.data = mlx_get_data_addr(g->mlx.img_p,
		&g->mlx.bpp, &g->mlx.sl, &g->mlx.endian);
}

void	set_pos(t_global *g)
{
	int		i;
	int		j;
	int		pos;

	i = 0;
	pos = 0;
	while (i < g->map->nb_lines && !pos)
	{
		j = 0;
		while (j < g->map->len_line[i])
		{
			if (g->map->line[i][j] == 0 && !pos)
			{
				g->pos.x = j + 0.5;
				g->pos.y = i + 0.5;
				pos = 1;
			}
			j++;
		}
		i++;
	}
	g->pos.dirx = 0;
	g->pos.diry = -1;
	g->pos.plan_x = 0.66;
	g->pos.plan_y = 0;
}

void	set_key(t_global *g)
{
	g->key.u = 0;
	g->key.d = 0;
	g->key.l = 0;
	g->key.r = 0;
}

void	set_ray(t_global *g, int x)
{
	g->ray.dirx = g->pos.dirx + g->pos.plan_x * (2 * x / (double)WIDTH - 1.0);
	g->ray.diry = g->pos.diry + g->pos.plan_y * (2 * x / (double)WIDTH - 1.0);
	g->ray.x = g->pos.x;
	g->ray.y = g->pos.y;
}
