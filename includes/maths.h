/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 23:17:25 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/13 23:17:26 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include "struct.h"

void		set_some_values(t_global *g);
void		get_value_wall(t_global *g);
void		set_step_and_side_dist(t_global *g);
void		hit_wall_and_set_color(t_global *g);

#endif
