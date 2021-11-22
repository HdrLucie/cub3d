/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:47:47 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:47:48 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

void	ft_set_move_var(t_env *env)
{
	env->move.m_speed = 0;
	env->move.r_speed = 0.02;
}

int	ft_key_pressed(int keycode, t_env *env)
{
	if (keycode == HAND)
		env->event->hand = 1;
	else if (keycode == KEYCODE_A)
		env->event->go_left = 1;
	else if (keycode == KEYCODE_D)
		env->event->go_right = 1;
	else if (keycode == KEYCODE_W)
		env->event->go_forward = 1;
	else if (keycode == KEYCODE_S)
		env->event->go_backward = 1;
	else if (keycode == KEYCODE_RIGHT)
		env->event->turn_right = 1;
	else if (keycode == KEYCODE_LEFT)
		env->event->turn_left = 1;
	else if (keycode == KEYCODE_P)
		env->event->door = 1;
	else if (keycode == ESCAPE)
		env->event->escape = 1;
	return (0);
}

int	ft_key_released(int keycode, t_env *env)
{
	if (keycode == HAND)
		env->event->hand = 0;
	else if (keycode == KEYCODE_A)
		env->event->go_left = 0;
	else if (keycode == KEYCODE_D)
		env->event->go_right = 0;
	else if (keycode == KEYCODE_W)
		env->event->go_forward = 0;
	else if (keycode == KEYCODE_S)
		env->event->go_backward = 0;
	else if (keycode == KEYCODE_RIGHT)
		env->event->turn_right = 0;
	else if (keycode == KEYCODE_LEFT)
		env->event->turn_left = 0;
	else if (keycode == KEYCODE_P)
		env->event->door = 0;
	return (0);
}
