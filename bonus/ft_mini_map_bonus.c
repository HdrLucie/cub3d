/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:47:18 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 02:33:02 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

/*
** In that file, I calculate the size of my mini map, 
** I browse my mini map and draw each pixel depending 
** if it's a wall or not, a sprite, or position player.
*/

void	ft_calcul_mini_map(t_env *env)
{
	int	y;
	int	x;
	int	a;
	int	b;

	a = 0;
	b = 0;
	y = -1;
	x = 0;
	while (++y <= env->size_map)
	{
		while (env->map[y][x])
			x++;
		if (a < x)
			a = x;
		x = 0;
	}
	env->mini_map_size.width = a;
	env->mini_map_size.height = env->size_map;
}

int	ft_check_color(char c)
{
	if (c == '1')
		return (0x00A351);
	else if (ft_is_in_str("234567", c))
		return (0xFF0000);
	else
		return (0xFFFFFF);
}

void	ft_print_position_player(t_env *env)
{
	int	i;
	int	j;
	int	pixel;

	pixel = 4;
	j = -1;
	i = -1;
	while (++j < pixel)
	{
		while (++i < pixel)
		{
			ft_my_mlx_pixel_put(env, env->player->pos.x
				* env->mini_map_size.height + 5 + i,
				env->player->pos.y * env->mini_map_size.width
				+ 5 + j, 0x000000);
		}
		i = -1;
	}
}

void	ft_print_pixel(t_env *env, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	env->colors.ptr = ft_check_color(env->map[y][x]);
	while (j <= env->mini_map_size.height)
	{
		while (i <= env->mini_map_size.width)
		{
			ft_my_mlx_pixel_put(env, x * env->mini_map_size.height
				+ 5 + j, y * env->mini_map_size.width
				+ 5 + i, env->colors.ptr);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_draw_mini_map(t_env *env)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	if (env->mlx->w.width > 200 && env->mlx->w.height > 200)
	{
		while (++y < env->mini_map_size.height)
		{
			while (env->map[y][++x])
				ft_print_pixel(env, y, x);
			ft_print_position_player(env);
			x = -1;
		}
	}
}
