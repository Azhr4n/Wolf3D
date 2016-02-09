/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:11:46 by pivanovi          #+#    #+#             */
/*   Updated: 2016/02/09 16:42:43 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "defines.h"
#include "parser.h"
#include "tools.h"

static int	get_len_line(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int	map_parser(char ***tab, int fd)
{
	char	*line;
	int		inc;

	inc = 0;
	while (get_next_line(fd, &line))
	{
		tab[inc] = ft_strsplit(line, ' ');
		free(line);
		inc++;
	}
	return (inc);
}

static void	fill_map_part2(t_map *map, char ***tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->nb_lines)
	{
		map->len_line[i] = get_len_line(tab[i]);
		if (!(map->line[i] = (int *)malloc(sizeof(int) * map->len_line[i])))
		{
			ft_putstr_e("Error with malloc (map->line[i]) !\n");
			exit(-1);
		}
		j = 0;
		while (j < map->len_line[i])
		{
			map->line[i][j] = ft_atof(tab[i][j]);
			++j;
		}
		++i;
	}
}

static void	fill_map_part3(t_map *map)
{
	if (!(map->len_line = (int *)malloc(sizeof(int) * map->nb_lines)))
	{
		ft_putstr_e("Error with malloc (map->len_line) !\n");
		exit(-1);
	}
	if (!(map->line = (int **)malloc(sizeof(int *) * map->nb_lines)))
	{
		ft_putstr_e("Error with malloc (map->line) !\n");
		exit(-1);
	}
}

t_map		*fill_map(char *path)
{
	t_map	*map;
	char	***tab;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (!(tab = (char ***)malloc(sizeof(char **) * MAX_LINES)))
	{
		ft_putstr_e("Error with malloc (tab) !\n");
		exit(-1);
	}
	i = -1;
	while (++i < MAX_LINES)
		tab[i] = 0;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
	{
		ft_putstr_e("Error with malloc (map) !\n");
		exit(-1);
	}
	map->nb_lines = map_parser(tab, fd);
	fill_map_part3(map);
	fill_map_part2(map, tab);
	free_tab_3d(tab);
	return (map);
}
