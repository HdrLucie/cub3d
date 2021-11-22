/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:46:59 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:47:00 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

void	ft_init_hud_tools(t_hud_tools *hud_tools)
{
	hud_tools->draw_start = 0;
	hud_tools->draw_end = 0;
	hud_tools->hud_texture = 0;
	hud_tools->index = 0;
	hud_tools->line_height = 0;
	hud_tools->tex.x = 0;
	hud_tools->tex.y = 0;
}

t_texture	*ft_create_HUD(t_env *env)
{
	char		*path;
	t_texture	*pdv;
	int			i;

	i = 0;
	pdv = NULL;
	path = "./pictures/pdv.xpm";
	pdv = malloc(sizeof(t_texture) * 2);
	if (!(pdv))
		ft_free_and_quit(env);
	pdv->data.img = mlx_xpm_file_to_image(env->mlx->mlx_ptr,
			path, &(pdv->width), &(pdv->height));
	if (pdv->data.img == NULL)
		ft_free_and_quit(env);
	pdv->data.adress = mlx_get_data_addr(pdv->data.img,
			&(pdv->data.bpp), &(pdv->data.line_lgt),
			&(pdv->data.endian));
	return (pdv);
}

t_texture	*ft_game_over_text(t_env *env)
{
	char		*path;
	t_texture	*end;
	int			i;

	i = 0;
	end = NULL;
	path = "./pictures/YouLose.xpm";
	end = malloc(sizeof(t_texture) * 2);
	if (!(end))
		ft_free_and_quit(env);
	end->data.img = mlx_xpm_file_to_image(env->mlx->mlx_ptr,
			path, &(end->width), &(end->height));
	if (end->data.img == NULL)
		ft_free_and_quit(env);
	end->data.adress = mlx_get_data_addr(end->data.img,
			&(end->data.bpp), &(end->data.line_lgt),
			&(end->data.endian));
	return (end);
}

void	ft_draw_end(t_env *env)
{
	int		i;
	int		j;
	int		end_text_offset;

	i = 0;
	j = 0;
	end_text_offset = env->mlx->w.width / 2 - env->end[0].width / 2;
	while (j <= env->end[0].height - 1)
	{
		while (i <= env->end[0].width)
		{
			env->colors.ptr = ((int *)env->end[0].data.adress)
			[(j * (env->end->width) + i)];
			if (!(env->colors.ptr >= 65275 && env->colors.ptr <= 65295))
				ft_my_mlx_pixel_put(env, end_text_offset + i,
					env->mlx->w.height / 2 - env->end[0].height
					/ 2 + j, env->colors.ptr);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_draw_pdv(t_env *env)
{
	int		i;
	int		j;
	int		index_pdv;
	int		pdv_text_offset;

	i = 0;
	j = 0;
	pdv_text_offset = env->mlx->w.width / 2 - env->pdv[0].width / 2;
	index_pdv = 0;
	while (j <= env->pdv[0].height / 5)
	{
		while (i <= env->pdv[0].width)
		{
			index_pdv = (env->pdv[0].height / 5) * (5 - env->player->pdv);
			env->colors.ptr = ((int *)env->pdv[0].data.adress)[(j + index_pdv)
				*(env->pdv->width) + i];
			if (!(env->colors.ptr >= 65275 && env->colors.ptr <= 65295))
				ft_my_mlx_pixel_put(env, pdv_text_offset + i,
					env->mlx->w.height - env->pdv[0].height
					/ 5 + j, env->colors.ptr);
			i++;
		}
		i = 0;
		j++;
	}
}
