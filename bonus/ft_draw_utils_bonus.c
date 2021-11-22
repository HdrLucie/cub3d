/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:18:16 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:46:56 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

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
				ft_my_mlx_pixel_put(env, x, y, create_trgb(0,
						env->colors.sky_red, env->colors.sky_green,
						env->colors.sky_blue));
			else
				ft_my_mlx_pixel_put(env, x, y, create_trgb(0,
						env->colors.floor_red, env->colors.floor_green,
						env->colors.floor_blue));
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;
	int		counter;

	counter = 0;
	dst = env->data->adress + (y * env->data->line_lgt
			+ x * (env->data->bpp / 8));
	if (env->player->invicibility * 100 > color >> 16)
		color = (color & 0xFF00FFFF)
			| (int)(100 * env->player->invicibility) << 16;
	if (env->player->drug_bottle)
	{
		if (counter == 0)
		{
			color = (color & 0xFF00FFFF)
				| ((int)(100 * env->player->drug_bottle) << 16);
			counter = 1;
		}
		else
		{
			color = ((color & 0xFFFFFF00)
					| (int)(100 * env->player->drug_bottle));
			counter = 0;
		}
	}
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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
