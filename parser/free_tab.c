/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 02:29:39 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/04 02:29:39 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "defines.h"
#include "parser.h"
#include "tools.h"

void		free_tab_3d(char ***tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			free(tab[i][j]);
			++j;
		}
		free(tab[i]);
		++i;
	}
	free(tab);
}
