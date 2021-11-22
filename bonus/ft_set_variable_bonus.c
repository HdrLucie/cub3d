/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_variable_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:44:33 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 02:21:54 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

void	ft_init_flag_texture(t_env *env)
{
	env->error.flag_texture[0] = 0;
	env->error.flag_texture[1] = 0;
	env->error.flag_texture[2] = 0;
	env->error.flag_texture[3] = 0;
	env->error.flag_sprite[0] = 0;
	env->error.flag_sprite[1] = 0;
	env->error.flag_sprite[2] = 0;
	env->error.flag_sprite[3] = 0;
	env->error.flag_sprite[4] = 0;
}

void	set_error_flag(t_env *env)
{
	env->error.ceilling_color = 0;
	env->error.counter_pos = 0;
	env->error.floor_color = 0;
	env->error.map_error = 0;
	env->colors.floor_blue = -1;
	env->colors.floor_red = -1;
	env->colors.floor_green = -1;
	env->colors.sky_blue = -1;
	env->colors.sky_green = -1;
	env->colors.sky_red = -1;
}

/*
** In that function, I initialize my variables.
** ray_dir are the direction of my rays,
** map.x and map.y are the position of player.
** deltadist : distance between two intersections.
** w_dist : distance between position and a wall.
** l_height: wall's height.
** drawStart, drawEnd : where I start to draw and where I finish.
** texX, texY : position of my txture on the wall.	
*/

void	ft_init_draw_tools(t_draw_tools *draw_tools, t_env *env, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)env->mlx->w.width - 1;
	draw_tools->ray_dir.x = env->player->dir.x
		+ env->player->plane.x * camera_x;
	draw_tools->ray_dir.y = env->player->dir.y
		+ env->player->plane.y * camera_x;
	draw_tools->map.x = (int)(env->player->pos.x);
	draw_tools->map.y = (int)(env->player->pos.y);
	draw_tools->delta_dist.x = fabs(1 / draw_tools->ray_dir.x);
	draw_tools->delta_dist.y = fabs(1 / draw_tools->ray_dir.y);
	draw_tools->hit = 0;
	draw_tools->d_end = 0;
	draw_tools->d_start = 0;
	draw_tools->w_dist = 0;
}

void	ft_set_variables(t_env *env)
{
	env->nb_text = 0;
	env->path = NULL;
	env->mlx = NULL;
	env->texture = NULL;
	env->map = NULL;
	env->size_map = 0;
	env->player = NULL;
	env->data = NULL;
	env->sprite = NULL;
	env->s_order = NULL;
	env->s_dist = NULL;
	env->pdv = NULL;
	env->hand = NULL;
	env->end = NULL;
	env->event = NULL;
	env->s_tools = NULL;
	env->zbuffer = NULL;
	env->sprite_text = NULL;
	env->delta_time = clock();
	env->last_time = clock();
}

t_event	*ft_init_event(void)
{
	t_event	*event;

	event = malloc(sizeof(t_event));
	if (!(event))
		return (NULL);
	event->door = 0;
	event->escape = 0;
	event->go_backward = 0;
	event->go_forward = 0;
	event->go_left = 0;
	event->go_right = 0;
	event->turn_left = 0;
	event->turn_right = 0;
	event->hand = 0;
	return (event);
}
