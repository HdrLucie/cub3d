/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:47:07 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:47:08 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

void	set_data_texture(t_env *env)
{
	env->texture[0].data.img = NULL;
	env->texture[1].data.img = NULL;
	env->texture[2].data.img = NULL;
	env->texture[3].data.img = NULL;
}

void	set_data_sprite(t_env *env)
{
	env->sprite_text[0].data.img = NULL;
	env->sprite_text[1].data.img = NULL;
	env->sprite_text[2].data.img = NULL;
	env->sprite_text[3].data.img = NULL;
	env->sprite_text[4].data.img = NULL;
	env->sprite_text[5].data.img = NULL;
}

void	ft_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

t_data	*ft_init_img(t_env *env)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!(data))
		return (NULL);
	data->img = mlx_new_image(env->mlx->mlx_ptr,
			env->mlx->w.width, env->mlx->w.height);
	if (!(data->img))
		ft_free_and_quit(env);
	data->adress = mlx_get_data_addr(data->img, &(data->bpp),
			&(data->line_lgt), &(data->endian));
	if (!(data->adress))
		ft_free_and_quit(env);
	return (data);
}

t_mlx	*ft_mlx_init(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!(mlx))
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = NULL;
	return (mlx);
}
