/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:18:16 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 01:55:05 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions.h"

/*
** In that function, I draw my floor and sky. 
** I split my window's width in two parts.
** I browse my window in height and width. I draw my sky
** until the middle of my width and my floor in the toher middle.
*/

void	ft_draw_roof(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < env->mlx->w.height)
	{
		while (x < env->mlx->w.width)
		{
			if (y < env->mlx->w.height / 2)
				ft_my_mlx_pixel_put(env->data, x, y, create_trgb(0,
						env->colors.sky_red, env->colors.sky_green,
						env->colors.sky_blue));
			else
				ft_my_mlx_pixel_put(env->data, x, y, create_trgb(0,
						env->colors.floor_red, env->colors.floor_green,
						env->colors.floor_blue));
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adress + (y * data->line_lgt + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
** In that function, I calculate the wall's size. 
** In order to do that, I split the window's height by the
** distance between the player and a wall.
*/

void	ft_calc_wall_size(t_draw_tools *draw_tools, t_env *env)
{
	draw_tools->l_height = (int)(env->mlx->w.height / draw_tools->w_dist);
	draw_tools->d_start = -(draw_tools->l_height) / 2 + env->mlx->w.height / 2;
	if (draw_tools->d_start < 0)
		draw_tools->d_start = 0;
	draw_tools->d_end = draw_tools->l_height / 2 + env->mlx->w.height / 2;
	if (draw_tools->d_end >= env->mlx->w.height)
		draw_tools->d_end = env->mlx->w.height - 1;
}

/*
** In that function, I want to know which wall I hit.
** And depending om the wall I hit (if dir.y or dir.x
** and if it's positive or not), I put a different
** index for each texture. 
*/

void	ft_find_wall_texture(t_draw_tools *draw_tools)
{
	if (draw_tools->side == 1)
	{
		if (draw_tools->ray_dir.y > 0)
			draw_tools->wall_text = 0;
		else
			draw_tools->wall_text = 1;
	}
	else
	{
		if (draw_tools->ray_dir.x > 0)
			draw_tools->wall_text = 2;
		else
			draw_tools->wall_text = 3;
	}
}
