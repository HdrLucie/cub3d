/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:18:32 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:45:08 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions.h"

void	ft_set_move_var(t_env *env)
{
	env->move.m_speed = 0.1;
	env->move.r_speed = 0.1;
	env->move.old_dir = env->player->dir.x;
	env->move.old_plane = env->player->plane.x;
}

void	ft_move_camera(int keycode, t_env *env)
{
	if (keycode == KEYCODE_RIGHT)
	{
		env->player->dir.x = env->player->dir.x * cos(-env->move.r_speed)
			- env->player->dir.y * sin(-env->move.r_speed);
		env->player->dir.y = env->move.old_dir * sin(-env->move.r_speed)
			+ env->player->dir.y * cos(-env->move.r_speed);
		env->player->plane.x = env->player->plane.x * cos(-env->move.r_speed)
			- env->player->plane.y * sin(-env->move.r_speed);
		env->player->plane.y = env->move.old_plane * sin(-env->move.r_speed)
			+ env->player->plane.y * cos(-env->move.r_speed);
	}
	else if (keycode == KEYCODE_LEFT)
	{
		env->player->dir.x = env->player->dir.x * cos(env->move.r_speed)
			- env->player->dir.y * sin(env->move.r_speed);
		env->player->dir.y = env->move.old_dir * sin(env->move.r_speed)
			+ env->player->dir.y * cos(env->move.r_speed);
		env->player->plane.x = env->player->plane.x * cos(env->move.r_speed)
			- env->player->plane.y * sin(env->move.r_speed);
		env->player->plane.y = env->move.old_plane * sin(env->move.r_speed)
			+ env->player->plane.y * cos(env->move.r_speed);
	}
}

void	ft_move(int keycode, t_env *env)
{
	if (keycode == KEYCODE_D)
	{
		if (env->map[(int)(env->player->pos.y)][(int)((env->player->pos.x
			+ env->player->plane.x * env->move.m_speed))] == '0')
			env->player->pos.x += env->player->plane.x * env->move.m_speed;
		if (env->map[(int)((env->player->pos.y + env->player->plane.y
					* env->move.m_speed))][(int)(env->player->pos.x)] == '0')
			env->player->pos.y += env->player->plane.y * env->move.m_speed;
	}
	else if (keycode == KEYCODE_S)
	{
		if (env->map[(int)(env->player->pos.y - env->player->dir.y
				* env->move.m_speed)][(int)env->player->pos.x] == '0')
			env->player->pos.y -= env->player->dir.y * env->move.m_speed;
		if (env->map[(int)env->player->pos.y][(int)(env->player->pos.x
			- env->player->dir.x * env->move.m_speed)] == '0')
			env->player->pos.x -= env->player->dir.x * env->move.m_speed;
	}
}

void	ft_lateral_move(int keycode, t_env *env)
{
	if (keycode == KEYCODE_W)
	{
		if (env->map[(int)(env->player->pos.y + env->player->dir.y
				* env->move.m_speed)][(int)env->player->pos.x] == '0')
			env->player->pos.y += env->player->dir.y * env->move.m_speed;
		if (env->map[(int)env->player->pos.y][(int)(env->player->pos.x
			+ env->player->dir.x * env->move.m_speed)] == '0')
			env->player->pos.x += env->player->dir.x * env->move.m_speed;
	}
	else if (keycode == KEYCODE_A)
	{
		if (env->map[(int)(env->player->pos.y)][(int)((env->player->pos.x
			- env->player->plane.x * env->move.m_speed))] == '0')
			env->player->pos.x -= env->player->plane.x * env->move.m_speed;
		if (env->map[(int)((env->player->pos.y - env->player->plane.y
					* env->move.m_speed))][(int)(env->player->pos.x)] == '0')
			env->player->pos.y -= env->player->plane.y * env->move.m_speed;
	}
}

int	ft_deal_key(int keycode, t_env *env)
{
	ft_set_move_var(env);
	mlx_clear_window(env->mlx->mlx_ptr, env->mlx->win_ptr);
	if (keycode == 65307)
		ft_free_and_quit(env);
	ft_lateral_move(keycode, env);
	ft_move(keycode, env);
	ft_move_camera(keycode, env);
	ft_draw_frame(env);
	return (1);
}
