/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 23:34:17 by pivanovi          #+#    #+#             */
/*   Updated: 2014/05/04 23:34:17 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_map
{
	int				nb_lines;
	int				*len_line;
	int				**line;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	char			*data;
	int				bpp;
	int				sl;
	int				endian;
	int				color;
}					t_mlx;

typedef struct		s_key
{
	int				u;
	int				d;
	int				l;
	int				r;
}					t_key;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_ray
{
	double			x;
	double			y;
	double			dirx;
	double			diry;
}					t_ray;

typedef struct		s_cam
{
	double			x;
	double			y;
	double			dirx;
	double			diry;
	double			posx;
	double			posy;
	double			plan_x;
	double			plan_y;
}					t_cam;

typedef struct		s_val
{
	double			dist_x;
	double			dist_y;
	double			norm_wall;
	double			side_dist_x;
	double			side_dist_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				step_x;
	int				step_y;
	int				color;
	int				side;
	int				hit;
}					t_val;

typedef struct		s_global
{
	t_map			*map;
	t_mlx			mlx;
	t_cam			pos;
	t_ray			ray;
	t_val			val;
	t_key			key;
}					t_global;

#endif
