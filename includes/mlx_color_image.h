/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color_image.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 23:04:20 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/13 23:04:21 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COLOR_IMAGE_H
# define MLX_COLOR_IMAGE_H

# include "struct.h"

void		full_image(t_global *g, int x);
void		put_color_image(t_global *g, int x, int i, int color);

#endif
