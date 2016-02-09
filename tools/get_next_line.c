/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 19:24:00 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/07 19:24:00 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 33.1.0
*/

#include <unistd.h>
#include <stdlib.h>

#include "defines.h"
#include "tools.h"

static int	check_if_c(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	slide_buffer(char *buffer, int pos)
{
	int		i;

	i = 0;
	while (buffer[pos + i])
	{
		buffer[i] = buffer[pos + i];
		buffer[pos + i] = '\0';
		i++;
	}
	while (buffer[i])
	{
		buffer[i] = '\0';
		i++;
	}
}

static void	cpb_next(char **line, char *tmp)
{
	char	*cpy;

	if (*line)
	{
		cpy = ft_strjoin(*line, tmp);
		free(*line);
		free(tmp);
		*line = cpy;
	}
	else
		*line = tmp;
}

static void	copy_part_buffer(char **line, char *buffer)
{
	char	*tmp;
	int		stop;
	int		i;

	if (!(tmp = (char*)malloc(sizeof(char) * BUFFSIZE)))
		return ;
	i = 0;
	stop = 0;
	while (stop != 1)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0' || i == BUFFSIZE)
		{
			tmp[i] = '\0';
			stop = 1;
		}
		else
		{
			tmp[i] = buffer[i];
			buffer[i] = '\0';
		}
		i++;
	}
	cpb_next(line, tmp);
	slide_buffer(buffer, i);
}

int			get_next_line(int fd, char **line)
{
	static char		buffer[BUFFSIZE + 1] = {0};
	int				stop;
	int				ret;

	stop = 0;
	ret = 1;
	*line = NULL;
	while (ret != 0 && stop != 1)
	{
		if (!buffer[0])
		{
			if ((ret = read(fd, buffer, BUFFSIZE)) == -1)
				return (-1);
		}
		else
		{
			if ((stop = check_if_c(buffer, '\n')))
				copy_part_buffer(line, buffer);
			else
				copy_part_buffer(line, buffer);
		}
	}
	return (ret);
}
