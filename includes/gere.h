/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 22:35:26 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/13 22:35:27 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GERE_H
# define GERE_H

# include "struct.h"

int		gere_key_down(int key, t_global *g);
int		gere_key_up(int key, t_global *g);

#endif
