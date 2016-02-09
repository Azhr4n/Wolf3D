/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 22:34:51 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/13 22:34:52 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "defines.h"
#include "struct.h"
#include "gere.h"

int		gere_key_down(int key, t_global *g)
{
	if (key == ESC)
		exit(0);
	if (key == U_ARROW)
		g->key.u = 1;
	if (key == D_ARROW && !g->key.u)
		g->key.d = 1;
	if (key == L_ARROW)
		g->key.l = 1;
	if (key == R_ARROW)
		g->key.r = 1;
	return (0);
}

int		gere_key_up(int key, t_global *g)
{
	if (key == ESC)
		exit(0);
	if (key == U_ARROW)
		g->key.u = 0;
	if (key == D_ARROW)
		g->key.d = 0;
	if (key == L_ARROW)
		g->key.l = 0;
	if (key == R_ARROW)
		g->key.r = 0;
	return (0);
}
