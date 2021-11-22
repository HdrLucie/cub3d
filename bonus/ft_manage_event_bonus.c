/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:47:14 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:47:15 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

void	ft_move_camera(t_env *env)
{
	if (env->event->turn_right)
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
	if (env->event->turn_left)
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

void	ft_if_event(t_env *env)
{
	ft_bottles_effects(env);
	env->move.old_dir = env->player->dir.x;
	env->move.old_plane = env->player->plane.x;
	if (env->move.m_speed <= 0.01)
		env->move.m_speed += env->delta_time / 1000000.0;
	else if (env->move.m_speed > 0.01)
		env->move.m_speed = 0.01;
	if (env->event->escape)
		ft_free_and_quit(env);
	ft_go_right(env);
	ft_go_backward(env);
	ft_go_forward(env);
	ft_go_left(env);
	ft_move_camera(env);
	ft_sprites_effects(env);
	ft_animation_door(env);
	ft_hit_ennemy(env);
}

int	ft_deal_key(t_env *env)
{
	env->delta_time = clock() - env->last_time;
	ft_check_var_player(env);
	if (env->event->escape || env->event->go_backward || env->event->go_forward
		|| env->event->go_left || env->event->go_right || env->event->turn_left
		|| env->event->turn_right || env->event->hand || env->event->door)
		ft_if_event(env);
	else
	{
		if (env->move.m_speed > 0)
			env->move.m_speed -= 0.01;
		else if (env->move.m_speed < 0)
			env->move.m_speed = 0;
	}
	ft_hit_hand(env);
	env->last_time = clock();
	return (1);
}
