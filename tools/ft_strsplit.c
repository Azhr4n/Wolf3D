/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:29:02 by pivanovi          #+#    #+#             */
/*   Updated: 2016/02/09 16:42:14 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

static int	get_nb_lines(char *str, char c)
{
	int		i;
	int		inc;

	i = 0;
	inc = 1;
	while (str[i])
	{
		if (str[i] == c)
			inc++;
		i++;
	}
	return (inc);
}

static int	get_len_line(char *pos, char c)
{
	int		i;

	i = 0;
	while (pos[i] != c && pos[i])
		i++;
	return (i);
}

static void	ft_strsplit_part2(char *str, char c, char **tab, int len)
{
	int		len2;
	int		i;
	int		j;

	i = 0;
	while (*str && i < len)
	{
		len2 = get_len_line(str, c);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (len2 + 1))))
		{
			ft_putstr_e("Error with second malloc in ft_strsplit.c !\n");
			exit(-1);
		}
		j = 0;
		while (j < len2)
		{
			tab[i][j] = *str;
			str++;
			j++;
		}
		while (*str && *str == c)
			str++;
		i++;
	}
}

char		**ft_strsplit(char *str, char c)
{
	char	**tab;
	int		len;

	len = get_nb_lines(str, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
	{
		ft_putstr_e("Error with first malloc in ft_strsplit.c !\n");
		exit(-1);
	}
	tab[len] = 0;
	ft_strsplit_part2(str, c, tab, len);
	return (tab);
}
