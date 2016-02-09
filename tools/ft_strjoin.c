/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:17:55 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/03 18:17:55 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

char		*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))))
	{
		ft_putstr_e("Error malloc in ft_strjoin !\n");
		exit(-1);
	}
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
