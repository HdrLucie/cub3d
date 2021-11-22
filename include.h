/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:13:29 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:52:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

# define KEYCODE_W 119
# define KEYCODE_A 97
# define KEYCODE_S 115
# define KEYCODE_D 100
# define KEYCODE_RIGHT 65363
# define KEYCODE_LEFT 65361

typedef struct s_size
{
	int			width;
	int			height;
}				t_size;

typedef struct s_ivec2
{
	int			x;
	int			y;
}				t_ivec2;

typedef struct s_dvec2
{
	double		x;
	double		y;
}				t_dvec2;

typedef struct s_draw_tools
{
	int			hit;
	int			side;
	int			l_height;
	int			d_start;
	int			d_end;
	int			wall_text;
	double		w_dist;
	double		wall_x;
	t_ivec2		tex;
	t_ivec2		map;
	t_ivec2		step;
	t_dvec2		ray_dir;
	t_dvec2		s_dist;
	t_dvec2		delta_dist;
}				t_draw_tools;

typedef struct s_player
{
	t_dvec2		pos;
	t_dvec2		dir;
	t_dvec2		plane;
}				t_player;

typedef struct s_data
{
	void		*img;
	char		*adress;
	int			bpp;
	int			line_lgt;
	int			endian;
}				t_data;

typedef struct s_texture
{
	t_data		data;
	int			height;
	int			width;
	int			index;
}				t_texture;

typedef struct s_sprite
{
	t_dvec2		pos;
	t_size		s;
	int			index;
}				t_sprite;

typedef struct s_colors
{
	int			floor_transparency;
	int			floor_red;
	int			floor_green;
	int			floor_blue;
	int			sky_transparency;
	int			sky_red;
	int			sky_green;
	int			sky_blue;
	int			ptr;
}				t_colors;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_size		w;
}				t_mlx;

typedef struct s_error
{
	int			flag_texture[5];
	int			floor_color;
	int			ceilling_color;
	int			map_error;
	int			counter_pos;
}				t_error;

typedef struct s_move
{
	double		r_speed;
	double		old_dir;
	double		old_plane;
	double		m_speed;
}				t_move;

typedef struct s_env
{
	char		*path;
	int			size_map;
	int			nb_textures;
	char		**map;
	t_move		move;
	t_data		*data;
	t_mlx		*mlx;
	t_player	*player;
	t_texture	*texture;
	t_colors	colors;
	t_error		error;
}				t_env;

#endif
