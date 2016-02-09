/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 23:14:16 by pivanovi          #+#    #+#             */
/*   Updated: 2016/02/09 16:43:33 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "defines.h"
#include "struct.h"
#include "maths.h"

void		set_some_values(t_global *g)
{
	g->pos.posx = (int)g->ray.x;
	g->pos.posy = (int)g->ray.y;
	g->val.dist_x = sqrt(1 + (g->ray.diry * g->ray.diry)
		/ (g->ray.dirx * g->ray.dirx));
	g->val.dist_y = sqrt(1 + (g->ray.dirx * g->ray.dirx)
		/ (g->ray.diry * g->ray.diry));
	g->val.hit = 0;
}

void		get_value_wall(t_global *g)
{
	if (!g->val.side)
		g->val.norm_wall = fabs((g->pos.posx - g->ray.x +
			(1 - g->val.step_x) / 2) / g->ray.dirx);
	else
		g->val.norm_wall = fabs((g->pos.posy - g->ray.y
			+ (1 - g->val.step_y) / 2) / g->ray.diry);
	g->val.line_height = (int)fabs((HEIGHT / g->val.norm_wall));
	g->val.draw_start = (-g->val.line_height / 2) + (HEIGHT / 2);
	if (g->val.draw_start < 0)
		g->val.draw_start = 0;
	g->val.draw_end = (g->val.line_height / 2) + (HEIGHT / 2);
	if (g->val.draw_end > HEIGHT)
		g->val.draw_end = HEIGHT - 1;
}

void		set_step_and_side_dist(t_global *g)
{
	if (g->ray.dirx < 0)
	{
		g->val.step_x = -1;
		g->val.side_dist_x = (g->ray.x - g->pos.posx) * g->val.dist_x;
	}
	else
	{
		g->val.step_x = 1;
		g->val.side_dist_x = (g->pos.posx + 1.0 - g->ray.x) * g->val.dist_x;
	}
	if (g->ray.diry < 0)
	{
		g->val.step_y = -1;
		g->val.side_dist_y = (g->ray.y - g->pos.posy) * g->val.dist_y;
	}
	else
	{
		g->val.step_y = 1;
		g->val.side_dist_y = (g->pos.posy + 1.0 - g->ray.y) * g->val.dist_y;
	}
}

void		hit_wall_and_set_color(t_global *g)
{
	while (!g->val.hit)
	{
		if (g->val.side_dist_x < g->val.side_dist_y)
		{
			g->val.side_dist_x += g->val.dist_x;
			g->pos.posx += g->val.step_x;
			g->val.side = 0;
			if (g->val.step_x < 0)
				g->val.color = 0xd4d4d2;
			else
				g->val.color = 0xececea;
		}
		else
		{
			g->val.side_dist_y += g->val.dist_y;
			g->pos.posy += g->val.step_y;
			g->val.side = 1;
			if (g->val.step_y < 0)
				g->val.color = 0x545454;
			else
				g->val.color = 0x737373;
		}
		if (g->map->line[(int)g->pos.posy][(int)g->pos.posx] > 1)
			g->val.hit = 1;
	}
}
