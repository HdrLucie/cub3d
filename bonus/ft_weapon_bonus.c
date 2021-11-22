/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapon_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:48:01 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 04:40:48 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

/*
** In that file, I manage differents events : draw enemy, hit enemy,
** draw hands and hit hand. In the first function, I check if I push
** shift and set event and if sprite
** is an enemy (index 0), I trqnsform it.
*/

void	ft_draw_dead_ennemy(t_env *env)
{
	int	i;

	i = -1;
	if (env->player->hit_ennemy == 1)
	{
		if (env->sprite[env->s_order[env->nb_sprite - 1]].index == 0)
			env->sprite[env->s_order[env->nb_sprite - 1]].index = 3;
	}
}

/*
** In that function, I check if I'm near an enemy when I push shift.
** If it's the case, I set the hit_enemy event.
*/

void	ft_hit_ennemy(t_env *env)
{
	int	hit_ennemy;

	hit_ennemy = 0;
	if (env->event->hand == 1 && env->map[(int)(env->player->pos.y
			+ env->player->dir.y * env->move.m_speed)]
		[(int)env->player->pos.x] == '2')
	{
		env->player->hit_ennemy = 1;
		env->map[(int)(env->player->pos.y + env->player->dir.y
				* env->move.m_speed)][(int)env->player->pos.x] = '5';
	}
}

t_texture	*ft_create_hand_text(t_env *env)
{
	char		*path;
	t_texture	*hand;
	int			i;

	i = 0;
	hand = NULL;
	path = "./pictures/weapon.xpm";
	hand = malloc(sizeof(t_texture) * 2);
	if (!(hand))
		ft_free_and_quit(env);
	hand->data.img = mlx_xpm_file_to_image(env->mlx->mlx_ptr,
			path, &(hand->width), &(hand->height));
	if (!(hand->data.img))
		ft_free_and_quit(env);
	hand->data.adress = mlx_get_data_addr(hand->data.img,
			&(hand->data.bpp), &(hand->data.line_lgt),
			&(hand->data.endian));
	return (hand);
}

/*
** These functions allow me to cross my image to animate my hand.
** I've one image and I split it in function to frames I want.
** Then I cross my image in y then x, to stream it. 
*/

void	ft_hit_hand(t_env *env)
{
	int		i;
	float	counter;

	i = 0;
	counter = 0;
	if (env->player->hit_hand < 24 && env->player->hit_hand > 1.0)
		env->player->hit_hand += 0.1;
	else if (env->event->hand == 1)
		env->player->hit_hand = 1.1;
	else
		env->player->hit_hand = 1;
}

void	ft_draw_hand(t_env *env)
{
	int		i;
	int		j;
	int		index_hand;
	int		hand_text_offset;

	i = -1;
	j = -1;
	hand_text_offset = env->mlx->w.width / 2 - env->hand[0].width / 2;
	if (env->player->hit_hand == 24)
		env->player->hit_hand = 1.1;
	while (++j <= env->hand[0].height / 25)
	{
		while (++i <= env->hand[0].width)
		{
			index_hand = (env->hand[0].height / 25)
				* (25 - (int)env->player->hit_hand);
			env->colors.ptr = ((int *)env->hand[0].data.adress)
			[(j + index_hand) *(env->hand->width) + i];
			if (!(env->colors.ptr >= 65275 && env->colors.ptr <= 65295))
				ft_my_mlx_pixel_put(env, hand_text_offset + i,
					env->mlx->w.height - (env->hand[0].height) / 25
					+ j, env->colors.ptr);
		}
		i = -1;
	}
}
