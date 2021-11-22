/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:18:24 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/20 23:57:19 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions.h"

/*
** In that function, I browse my map and if I found a N, S, E or W, 
** I save my position. Then, I set my index at 0.
*/

void	ft_searsh_pos(t_env *env, t_player *player, int y)
{
	int		x;

	x = -1;
	while (env->map[y][++x])
	{
		if (ft_is_in_str("NSEW", env->map[y][x]))
		{
			player->pos.x = x;
			player->pos.y = y;
			if (env->map[y][x] == 'E')
				player->dir.x = -1;
			else if (env->map[y][x] == 'W')
				player->dir.x = 1;
			else if (env->map[y][x] == 'N')
				player->dir.y = -1;
			else if (env->map[y][x] == 'S')
				player->dir.y = 1;
			env->map[y][x] = '0';
		}
	}
	x = -1;
}

t_player	*ft_init_player(t_env *env)
{
	t_player	*player;
	int			y;

	y = -1;
	player = malloc(sizeof(t_player));
	if (player == NULL)
		ft_free_and_quit(env);
	player->pos.x = 0;
	player->pos.y = 0;
	player->dir.x = 0;
	player->dir.y = 0;
	while (++y < env->size_map)
		ft_searsh_pos(env, player, y);
	player->plane.x = 0.66 * player->dir.y;
	player->plane.y = -0.66 * player->dir.x;
	return (player);
}

int	ft_init(t_env *env, char *path)
{
	ft_set_variables(env);
	env->mlx = ft_mlx_init();
	if (!(env->mlx))
		return (0);
	env->map = ft_parser(env, path);
	if (!(env->map))
		return (0);
	env->mlx->win_ptr = mlx_new_window(env->mlx->mlx_ptr,
			env->mlx->w.width, env->mlx->w.height, "Window");
	if (!(env->mlx->win_ptr))
		return (0);
	env->data = ft_init_img(env);
	if (!(env->data))
		return (0);
	env->player = ft_init_player(env);
	if (!(env->player))
		return (0);
	return (1);
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
