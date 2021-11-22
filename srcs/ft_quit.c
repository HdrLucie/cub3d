/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:45:36 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 05:01:03 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions.h"

/*
** In that file, I free every variable.
** And I CHECK if they exist. 
*/

void	ft_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	ft_quit(t_env *env)
{
	if (env->player)
		free(env->player);
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
}

void	ft_free_and_quit(t_env *env)
{
	int		i;

	i = -1;
	if (env->texture)
	{
		while (++i < 4)
		{
			if (env->texture[i].data.img)
				mlx_destroy_image(env->mlx->mlx_ptr, env->texture[i].data.img);
		}
		free(env->texture);
	}
	i = -1;
	if (env->map)
	{
		while (++i < env->size_map + 1)
			free(env->map[i]);
		if (env->size_map > 1)
			free(env->map);
	}
	ft_quit(env);
	exit(0);
}
