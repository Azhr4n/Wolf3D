/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:41:13 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/03 18:41:13 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <X11/X.h>

#include "mlx_color_image.h"
#include "defines.h"
#include "setters.h"
#include "parser.h"
#include "struct.h"
#include "maths.h"
#include "tools.h"
#include "gere.h"
#include "keys.h"

static int	print(t_global *g)
{
	int		x;

	if (g->key.u)
		vertical_key(g, 0.025);
	if (g->key.d)
		vertical_key(g, -0.025);
	if (g->key.r)
		horizontal_key(g, 0.025);
	if (g->key.l)
		horizontal_key(g, -0.025);
	x = 0;
	while (x < WIDTH)
	{
		set_ray(g, x);
		set_some_values(g);
		set_step_and_side_dist(g);
		hit_wall_and_set_color(g);
		get_value_wall(g);
		full_image(g, x);
		x++;
	}
	mlx_put_image_to_window(g->mlx.mlx_p, g->mlx.win_p, g->mlx.img_p, 0, 0);
	return (0);
}

int			main(void)
{
	t_global	g;

	g.map = fill_map("map/map");
	set_mlx(&g);
	set_pos(&g);
	set_key(&g);
	mlx_loop_hook(g.mlx.mlx_p, print, &g);
	mlx_hook(g.mlx.win_p, KeyPress, KeyPressMask, gere_key_down, &g);
	mlx_hook(g.mlx.win_p, KeyRelease, KeyReleaseMask, gere_key_up, &g);
	mlx_loop(g.mlx.mlx_p);
	return (0);
}
