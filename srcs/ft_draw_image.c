/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:07:20 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 02:18:13 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions.h"

/*
** That function allows me to know in which direction the player is looking.
** So, I can know which value I have to increment to move forward in my map.
** I decrement x in order to go in left. I decrement y to get on in my map.
*/

void	ft_find_step(t_draw_tools *draw_tools, t_env *env)
{
	if (draw_tools->ray_dir.x < 0)
	{
		draw_tools->step.x = -1;
		draw_tools->s_dist.x = (env->player->pos.x - draw_tools->map.x)
			* draw_tools->delta_dist.x;
	}
	else
	{
		draw_tools->step.x = 1;
		draw_tools->s_dist.x = (draw_tools->map.x + 1.0 - env->player->pos.x)
			* draw_tools->delta_dist.x;
	}
	if (draw_tools->ray_dir.y < 0)
	{
		draw_tools->step.y = -1;
		draw_tools->s_dist.y = (env->player->pos.y - draw_tools->map.y)
			* draw_tools->delta_dist.y;
	}
	else
	{
		draw_tools->step.y = 1;
		draw_tools->s_dist.y = (draw_tools->map.y + 1.0 - env->player->pos.y)
			* draw_tools->delta_dist.y;
	}
}

/*
** In that function, I try to find a wall and calculate the
** distance with the help of my step, between the position
** and the wall hited. Side and delta are the distance 
** traveled by my ray to touch a wall and the side it touch it.
** It allows me to know how I should draw it.
*/

void	ft_find_a_wall(t_draw_tools *draw_tools, t_env *env)
{
	while (draw_tools->hit == 0)
	{
		if (draw_tools->s_dist.x < draw_tools->s_dist.y)
		{
			draw_tools->s_dist.x += draw_tools->delta_dist.x;
			draw_tools->map.x += draw_tools->step.x;
			draw_tools->side = 0;
		}
		else
		{
			draw_tools->s_dist.y += draw_tools->delta_dist.y;
			draw_tools->map.y += draw_tools->step.y;
			draw_tools->side = 1;
		}
		if (env->map[draw_tools->map.y][draw_tools->map.x] &&
			env->map[draw_tools->map.y][draw_tools->map.x] == '1')
			draw_tools->hit = 1;
	}
	draw_tools->w_dist = ft_float_ternaire(draw_tools->side == 0,
			((draw_tools->map.x - env->player->pos.x)
				+ (1 - draw_tools->step.x) / 2) / draw_tools->ray_dir.x + 0.1f,
			((draw_tools->map.y - env->player->pos.y)
				+ (1 - draw_tools->step.y) / 2) / draw_tools->ray_dir.y + 0.1f);
}

/*
** Here, I calculate how I should draw my texture in relation to the wall,
** relation to the position of player, distance between him and the wall...
** in order to adjust the texture.
** I recover the size of my stripe of my teture and which stripe is.
*/

void	ft_draw_texture(t_draw_tools *draw_tools, t_env *env)
{
	if (draw_tools->side == 0)
		draw_tools->wall_x = env->player->pos.y + draw_tools->w_dist
			* draw_tools->ray_dir.y;
	else
		draw_tools->wall_x = env->player->pos.x + draw_tools->w_dist
			* draw_tools->ray_dir.x;
	draw_tools->wall_x -= (int)(draw_tools->wall_x);
	draw_tools->tex.x = (int)(draw_tools->wall_x
			* env->texture[draw_tools->wall_text].width);
	if (draw_tools->side == 0 && draw_tools->ray_dir.x > 0)
		draw_tools->tex.x = env->texture[draw_tools->wall_text].width
			- draw_tools->tex.x - 1;
	if (draw_tools->side == 1 && draw_tools->ray_dir.y < 0)
		draw_tools->tex.x = env->texture[draw_tools->wall_text].width
			- draw_tools->tex.x - 1;
}

void	ft_texture_stripe(t_env *env, int x, t_draw_tools *draw_tools)
{
	int				d;
	int				y;

	ft_init_draw_tools(draw_tools, env, x);
	ft_find_step(draw_tools, env);
	ft_find_a_wall(draw_tools, env);
	ft_calc_wall_size(draw_tools, env);
	ft_find_wall_texture(draw_tools);
	ft_draw_texture(draw_tools, env);
	y = draw_tools->d_start;
	while (y++ < draw_tools->d_end - 1)
	{
		d = y * 256 - env->mlx->w.height * 128 + draw_tools->l_height * 128;
		draw_tools->tex.y = (((d * env->texture[draw_tools->wall_text].height)
					/ draw_tools->l_height) / 256);
		env->texture->index = (draw_tools->tex.y
				* env->texture[draw_tools->wall_text].width)
			+ (draw_tools->tex.x);
		env->colors.ptr = ((int *)env->texture[draw_tools->wall_text]
				.data.adress)[env->texture->index];
		ft_my_mlx_pixel_put(env->data, x, y, env->colors.ptr);
	}
}

int	ft_draw_frame(t_env *env)
{
	t_draw_tools	draw_tools;
	int				x;

	x = -1;
	ft_draw_roof(env);
	while (++x < env->mlx->w.width)
		ft_texture_stripe(env, x, &draw_tools);
	mlx_put_image_to_window(env->mlx->mlx_ptr,
		env->mlx->win_ptr, env->data->img, 0, 0);
	return (1);
}
