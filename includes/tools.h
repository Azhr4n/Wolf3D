/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:12:36 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/03 18:12:36 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putendl(char *str);
void		ft_putnbr(int n);

void		ft_putchar_e(char c);
void		ft_putstr_e(char *str);

char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);

float		ft_atof(char *str);

int			get_next_line(int fd, char **line);
char		**ft_strsplit(char *str, char c);

#endif
