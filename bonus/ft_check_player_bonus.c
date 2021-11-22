/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:46:06 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:46:07 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

void	ft_check_var_player(t_env *env)
{
	if (env->player->invicibility > 0)
		env->player->invicibility -= 0.01;
	else if (env->player->invicibility < 0)
		env->player->invicibility = 0;
	if (env->player->drug_bottle > 0)
		env->player->drug_bottle -= 0.001;
	else if (env->player->drug_bottle < 0)
		env->player->drug_bottle = 0;
	if (env->player->speed > 0)
		env->player->speed -= 0.1;
	else if (env->player->speed < 0)
		env->player->speed = 0;
}

void	ft_draw_door(t_env *env)
{
	int	i;

	i = -1;
	if (env->player->open_door == 1)
	{
		env->player->open_door++;
		if (env->sprite[env->s_order[env->nb_sprite - 1]].index == 1)
			env->sprite[env->s_order[env->nb_sprite - 1]].index = 4;
		else if (env->sprite[env->s_order[env->nb_sprite - 1]].index == 4)
			env->sprite[env->s_order[env->nb_sprite - 1]].index = 1;
	}
}

void	ft_animation_door(t_env *env)
{
	int		door_open;
	float	counter;

	door_open = 0;
	counter = 0;
	if (env->event->door == 1 && env->map[(int)(env->player->pos.y
			+ env->player->dir.y * env->move.m_speed)]
		[(int)env->player->pos.x] == '3')
	{
		env->event->door++;
		env->player->open_door = 1;
		env->map[(int)(env->player->pos.y + env->player->dir.y
				* env->move.m_speed)][(int)env->player->pos.x] = '6';
	}
	else if (env->event->door == 1 && env->map[(int)(env->player->pos.y
			+ env->player->dir.y * env->move.m_speed)]
		[(int)env->player->pos.x] == '6')
	{
		env->event->door++;
		env->player->open_door = 1;
		env->map[(int)(env->player->pos.y + env->player->dir.y
				* env->move.m_speed)][(int)env->player->pos.x] = '3';
	}
}

void	ft_bottles_effects(t_env *env)
{
	if (env->map[(int)(env->player->pos.y)][(int)((env->player->pos.x))] == '5')
		env->player->drug_bottle = 2;
	if (env->map[(int)(env->player->pos.y)][(int)((env->player->pos.x))] == '4'
		&& env->player->pdv < 5)
	{
		env->player->pdv += 1;
		env->player->visible = 1;
	}
}

void	ft_sprites_effects(t_env *env)
{
	if (env->map[(int)(env->player->pos.y)][(int)((env->player->pos.x))] == '2')
	{
		if (env->player->pdv > 0 && env->player->invicibility == 0)
		{
			env->player->pdv--;
			env->player->invicibility = 2;
		}
		else if (env->player->pdv == 0)
		{
			env->event->go_backward = -1;
			env->event->go_forward = -1;
			env->event->go_left = -1;
			env->event->go_right = -1;
			env->event->turn_left = -1;
			env->event->turn_right = -1;
		}
	}
}
