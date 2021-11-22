/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_control_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:19:04 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/20 01:57:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

void	ft_quit(t_env *env)
{
	if (env->data)
	{
		mlx_destroy_image(env->mlx->mlx_ptr, env->data->img);
		free(env->data);
	}
	if (env->mlx)
	{
		if (env->mlx->win_ptr)
			mlx_destroy_window(env->mlx->mlx_ptr, env->mlx->win_ptr);
		mlx_destroy_display(env->mlx->mlx_ptr);
		free(env->mlx->mlx_ptr);
		free(env->mlx);
	}
	free(env);
	exit(0);
}

void	ft_following_free(t_env *env)
{
	int	i;

	i = 0;
	if (env->hand)
	{
		if (env->hand[i].data.img)
			mlx_destroy_image(env->mlx->mlx_ptr, env->hand[i].data.img);
		free(env->hand);
	}
	if (env->zbuffer)
		free (env->zbuffer);
	if (env->s_order)
		free(env->s_order);
	if (env->s_dist)
		free(env->s_dist);
	if (env->player)
		free(env->player);
	if (env->s_tools)
		free(env->s_tools);
	if (env->sprite)
		free(env->sprite);
	if (env->event)
		free(env->event);
	ft_quit(env);
}

void	ft_free_img(t_env *env, int i)
{
	i = -1;
	if (env->sprite_text)
	{
		while (++i < 6)
			if (env->sprite_text[i].data.img)
				mlx_destroy_image(env->mlx->mlx_ptr,
					env->sprite_text[i].data.img);
		free(env->sprite_text);
	}
	i = 0;
	if (env->pdv)
	{
		if (env->pdv[i].data.img)
			mlx_destroy_image(env->mlx->mlx_ptr, env->pdv[i].data.img);
		free(env->pdv);
	}
	i = 0;
	if (env->end)
	{
		if (env->end[i].data.img)
			mlx_destroy_image(env->mlx->mlx_ptr, env->end[i].data.img);
		free(env->end);
	}
	ft_following_free(env);
}

void	ft_free_and_quit(t_env *env)
{
	int		i;

	i = -1;
	if (env->texture)
	{
		while (++i < 4)
			if (env->texture[i].data.img)
				mlx_destroy_image(env->mlx->mlx_ptr, env->texture[i].data.img);
		free(env->texture);
	}
	i = -1;
	if (env->map)
	{
		while (i++ < env->size_map)
			free(env->map[i]);
		if (env->size_map > 1)
			free(env->map);
	}
	ft_free_img(env, i);
}
