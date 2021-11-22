/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:18:24 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:47:04 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

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
	player->pdv = 5;
	player->invicibility = 0;
	player->drug_bottle = 0;
	player->visible = 0;
	player->speed = 0;
	player->open_door = 0;
	player->hit_hand = 1;
	player->enemy = 1;
	player->hit_ennemy = 0;
	return (player);
}

int	ft_following_init(t_env *env)
{
	env->zbuffer = malloc(env->mlx->w.width * sizeof(double));
	if (!(env->zbuffer))
		return (0);
	env->hand = ft_create_hand_text(env);
	if (!(env->hand))
		return (0);
	env->pdv = ft_create_HUD(env);
	if (!(env->pdv))
		return (0);
	env->end = ft_game_over_text(env);
	if (!(env->end))
		return (0);
	env->player = ft_init_player(env);
	if (!(env->player))
		return (0);
	env->sprite = ft_init_sprite(env);
	if (!(env->sprite))
		return (0);
	env->s_tools = ft_init_sprite_tools();
	if (!(env->s_tools))
		return (0);
	env->event = ft_init_event();
	if (!(env->event))
		return (0);
	return (1);
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
	ft_calcul_mini_map(env);
	ft_following_init(env);
	ft_set_move_var(env);
	return (1);
}
