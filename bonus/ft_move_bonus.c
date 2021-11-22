/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:18:32 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:47:22 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

void	ft_go_right(t_env *env)
{
	if (env->event->go_right)
	{
		if (env->map[(int)(env->player->pos.y)][(int)((env->player->pos.x
			+ env->player->plane.x * env->move.m_speed))] != '1'
			&& env->map[(int)(env->player->pos.y)][(int)((env->player->pos.x
			+ env->player->plane.x * env->move.m_speed))] != '3')
			env->player->pos.x += env->player->plane.x * env->move.m_speed;
		if (env->map[(int)((env->player->pos.y + env->player->plane.y
					* env->move.m_speed))][(int)(env->player->pos.x)] != '1'
			&& env->map[(int)((env->player->pos.y + env->player->plane.y
					* env->move.m_speed))][(int)(env->player->pos.x)] != '3')
			env->player->pos.y += env->player->plane.y * env->move.m_speed;
	}
}

void	ft_go_backward(t_env *env)
{
	if (env->event->go_backward)
	{
		if (env->map[(int)(env->player->pos.y - env->player->dir.y
				* env->move.m_speed)][(int)env->player->pos.x] != '1'
				&& env->map[(int)(env->player->pos.y - env->player->dir.y
				* env->move.m_speed)][(int)env->player->pos.x] != '3')
			env->player->pos.y -= env->player->dir.y * env->move.m_speed;
		if (env->map[(int)env->player->pos.y][(int)(env->player->pos.x
			- env->player->dir.x * env->move.m_speed)] != '1'
			&& env->map[(int)env->player->pos.y][(int)(env->player->pos.x
			- env->player->dir.x * env->move.m_speed)] != '3' )
			env->player->pos.x -= env->player->dir.x * env->move.m_speed;
	}
}

void	ft_go_forward(t_env *env)
{
	if (env->event->go_forward)
	{
		if (env->map[(int)(env->player->pos.y + env->player->dir.y
				* env->move.m_speed)][(int)env->player->pos.x] != '1'
			&& env->map[(int)(env->player->pos.y + env->player->dir.y
				* env->move.m_speed)][(int)env->player->pos.x] != '3')
			env->player->pos.y += env->player->dir.y * env->move.m_speed;
		if (env->map[(int)env->player->pos.y][(int)(env->player->pos.x
			+ env->player->dir.x * env->move.m_speed)] != '1'
			&& env->map[(int)env->player->pos.y][(int)(env->player->pos.x
			+ env->player->dir.x * env->move.m_speed)] != '3')
			env->player->pos.x += env->player->dir.x * env->move.m_speed;
	}
}

void	ft_go_left(t_env *env)
{
	if (env->event->go_left)
	{
		if (env->map[(int)(env->player->pos.y)][(int)((env->player->pos.x
			- env->player->plane.x * env->move.m_speed))] != '1'
			&& env->map[(int)(env->player->pos.y)][(int)((env->player->pos.x
			- env->player->plane.x * env->move.m_speed))] != '3')
			env->player->pos.x -= env->player->plane.x * env->move.m_speed;
		if (env->map[(int)((env->player->pos.y - env->player->plane.y
					* env->move.m_speed))][(int)(env->player->pos.x)] != '1'
				&& env->map[(int)((env->player->pos.y - env->player->plane.y
					* env->move.m_speed))][(int)(env->player->pos.x)] != '3')
			env->player->pos.y -= env->player->plane.y * env->move.m_speed;
	}
}
