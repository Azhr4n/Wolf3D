/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 22:36:52 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/13 22:36:52 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "struct.h"
#include "keys.h"

void		vertical_key(t_global *g, double value)
{
	if (g->map->line[(int)(g->pos.y + g->pos.diry * value)][(int)g->pos.x] <= 1)
		g->pos.y += g->pos.diry * value;
	if (g->map->line[(int)g->pos.y][(int)(g->pos.x + g->pos.dirx * value)] <= 1)
		g->pos.x += g->pos.dirx * value;
}

void		horizontal_key(t_global *g, double value)
{
	double	old;

	old = g->pos.dirx;
	g->pos.dirx = g->pos.dirx * cos(value) - g->pos.diry * sin(value);
	g->pos.diry = old * sin(value) + g->pos.diry * cos(value);
	old = g->pos.plan_x;
	g->pos.plan_x = g->pos.plan_x * cos(value) - g->pos.plan_y * sin(value);
	g->pos.plan_y = old * sin(value) + g->pos.plan_y * cos(value);
}
