/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:18:58 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 02:26:32 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

/*
** In that file, I initialize my sprite's tools.
** I browse my map, and if I find a number that is on the list 
** of my sprites (234567), I make an index. 
** I calculate the number of sprites too. 
*/

t_s_tools	*ft_init_sprite_tools(void)
{
	t_s_tools	*s_tools;

	s_tools = malloc(sizeof(t_s_tools));
	if (!(s_tools))
		return (NULL);
	s_tools->s_screen = 0;
	s_tools->index = 0;
	s_tools->s.height = 0;
	s_tools->s.width = 0;
	s_tools->transform.x = 0;
	s_tools->transform.y = 0;
	s_tools->sprite.x = 0;
	s_tools->sprite.y = 0;
	s_tools->start.x = 0;
	s_tools->start.y = 0;
	s_tools->end.x = 0;
	s_tools->end.y = 0;
	s_tools->tex.y = 0;
	s_tools->tex.x = 0;
	return (s_tools);
}

void	ft_index_sprite(t_env *env, int i, int y, int x)
{
	env->sprite[i].pos.x = x + 0.5;
	env->sprite[i].pos.y = y + 0.5;
	if (env->map[y][x] == '2')
		env->sprite[i].index = 0;
	else if (env->map[y][x] == '3')
		env->sprite[i].index = 1;
	else if (env->map[y][x] == '4')
		env->sprite[i].index = 2;
	else if (env->map[y][x] == '5')
		env->sprite[i].index = 3;
	else if (env->map[y][x] == '6')
		env->sprite[i].index = 4;
	else if (env->map[y][x] == '7')
		env->sprite[i].index = 5;
}

t_sprite	*ft_init_sprite(t_env *env)
{
	int		i;
	int		y;
	int		x;

	i = 0;
	y = -1;
	ft_calc_nb_sprite(env);
	while (++y < env->size_map)
	{
		x = -1;
		while (env->map[y][++x])
		{
			if (ft_is_in_str("234567", env->map[y][x]))
			{
				ft_index_sprite(env, i, y, x);
				i++;
			}
		}
	}
	return (env->sprite);
}

void	ft_set_utils_sprite(t_env *env)
{
	env->s_dist = malloc(sizeof(int) * env->nb_sprite);
	if (env->s_dist == NULL)
		ft_free_and_quit(env);
	env->s_order = malloc(sizeof(int) * env->nb_sprite);
	if (env->s_order == NULL)
		ft_free_and_quit(env);
	env->sprite = malloc(env->nb_sprite * sizeof(t_sprite));
	if (env->sprite == NULL)
		ft_free_and_quit(env);
}

t_sprite	*ft_calc_nb_sprite(t_env *env)
{
	int		y;
	int		x;

	y = -1;
	x = -1;
	env->nb_sprite = 0;
	while (++y < env->size_map)
	{
		while (env->map[y][++x])
		{
			if (ft_is_in_str("234567", env->map[y][x]))
				env->nb_sprite++;
		}
		x = -1;
	}
	ft_set_utils_sprite(env);
	return (env->sprite);
}
