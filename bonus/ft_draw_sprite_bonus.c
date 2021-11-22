/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:47:28 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:46:47 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

void	find_stripe(t_env *env, int stripe, int index)
{
	int		y;
	int		d;

	y = env->s_tools->start.y;
	d = 0;
	if (env->s_tools->transform.y > 0 && stripe > 0
		&& stripe < env->mlx->w.width
		&& env->s_tools->transform.y < env->zbuffer[stripe])
	{
		while (++y < env->s_tools->end.y)
		{
			d = y * 256 - env->mlx->w.height * 128
				+ env->s_tools->s.height * 128;
			(env->s_tools->tex.y) = (int)abs((((d
								* env->sprite_text[index].height)
							/ env->s_tools->s.height) / 256));
			env->s_tools->index = (env->s_tools->tex.y
					* env->sprite_text[index].width) + (env->s_tools->tex.x);
			env->colors.ptr = (((int *)(env->sprite_text[index].data.adress))
				[env->s_tools->index]);
			if (env->colors.ptr != 65280)
				ft_my_mlx_pixel_put(env, stripe, y, env->colors.ptr);
		}
		y = env->s_tools->start.y - 1;
	}
}

void	ft_draw_stripe(t_env *env, int index)
{
	int	stripe;

	stripe = env->s_tools->start.x;
	ft_draw_door(env);
	ft_draw_dead_ennemy(env);
	while (stripe < env->s_tools->end.x)
	{
		(env->s_tools->tex.x) = (int)abs(((256
						* (stripe - (-env->s_tools->s.width
								/ 2 + env->s_tools->s_screen))
						* env->sprite_text[index].width
						/ env->s_tools->s.width)) / 256);
		find_stripe(env, stripe, index);
		stripe++;
	}
}

void	ft_find_draw_zone(t_env *env, int index)
{
	env->s_tools->start.y = -(env->s_tools->s.height) / 2
		+ env->mlx->w.height / 2;
	if (env->s_tools->start.y < 0)
		env->s_tools->start.y = 0;
	env->s_tools->end.y = env->s_tools->s.height / 2 + env->mlx->w.height / 2;
	if (env->s_tools->end.y >= env->mlx->w.height)
		env->s_tools->end.y = env->mlx->w.height - 1;
	env->s_tools->s.width = (int)(env->mlx->w.height
			/ (env->s_tools->transform.y));
	env->s_tools->start.x = -(env->s_tools->s.width)
		/ 2 + env->s_tools->s_screen;
	if (env->s_tools->start.x < 0)
		env->s_tools->start.x = 0;
	env->s_tools->end.x = env->s_tools->s.width / 2
		+ env->s_tools->s_screen;
	if (env->s_tools->end.x >= env->mlx->w.width)
		env->s_tools->end.x = env->mlx->w.width - 1;
	ft_draw_stripe(env, index);
}

void	ft_order_sprite(t_env *env)
{
	int		i;
	int		tmp;

	i = -1;
	while (++i < env->nb_sprite)
	{
		env->s_order[i] = i;
		env->s_dist[i] = ((env->player->pos.x - env->sprite[i].pos.x)
				* (env->player->pos.x - env->sprite[i].pos.x)
				+ (env->player->pos.y - env->sprite[i].pos.y)
				* (env->player->pos.y - env->sprite[i].pos.y));
	}
	i = 0;
	while (i < env->nb_sprite - 1)
	{
		if (env->s_dist[env->s_order[i]] < env->s_dist[env->s_order[i + 1]])
		{
			tmp = env->s_order[i];
			env->s_order[i] = env->s_order[i + 1];
			env->s_order[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_draw_sprite(t_env *env)
{
	double		transform_x;
	int			i;
	double		inv_det;

	i = -1;
	ft_order_sprite(env);
	while (++i < env->nb_sprite)
	{
		env->s_tools->sprite.x = env->sprite[env->s_order[i]].pos.x
			- env->player->pos.x;
		env->s_tools->sprite.y = env->sprite[env->s_order[i]].pos.y
			- env->player->pos.y;
		inv_det = 1.0 / (env->player->plane.x * env->player->dir.y
				- env->player->dir.x * env->player->plane.y);
		transform_x = inv_det * (env->player->dir.y * env->s_tools->sprite.x
				- env->player->dir.x * env->s_tools->sprite.y);
		env->s_tools->transform.y = inv_det * (-(env->player->plane.y)
				* env->s_tools->sprite.x
				+ env->player->plane.x * env->s_tools->sprite.y);
		env->s_tools->s_screen = (int)((env->mlx->w.width / 2)
				* (1 + transform_x / env->s_tools->transform.y));
		env->s_tools->s.height = (int)(env->mlx->w.height
				/ (env->s_tools->transform.y));
		ft_find_draw_zone(env, env->sprite[env->s_order[i]].index);
	}
}
