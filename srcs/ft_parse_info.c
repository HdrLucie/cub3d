/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:18:42 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 00:30:35 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions.h"

void	ft_control_resolution(t_env *env)
{
	int	x_sreen_size;
	int	y_sreen_size;

	mlx_get_screen_size(env->mlx->mlx_ptr, &x_sreen_size, &y_sreen_size);
	if (env->mlx->w.width > x_sreen_size)
		env->mlx->w.width = x_sreen_size;
	if (env->mlx->w.height > y_sreen_size)
		env->mlx->w.height = y_sreen_size;
}

/*
** In that function, I check if my colors are valid. 
** These must be include between 0 and 255. 
*/

int	ft_control_color(t_env *env, char c)
{
	if (c == 'F')
	{
		if (env->colors.floor_blue < 0 || env->colors.floor_green < 0
			|| env->colors.floor_red < 0 || env->colors.floor_blue > 255
			|| env->colors.floor_green > 255 || env->colors.floor_red > 255)
			return (0);
	}
	else
	{
		if (env->colors.sky_blue < 0 || env->colors.sky_green < 0
			|| env->colors.sky_red < 0 || env->colors.sky_blue > 255
			|| env->colors.sky_green > 255 || env->colors.sky_red > 255)
			return (0);
	}
	return (1);
}

/*
** In this two functions, I get my values for each shade. 
** First, I pass all the spaces ans letters. 
** I check if the character is a number with atoi, if it's not, I quit.
** Then I pass the number and spacs and comma.
** I repat that process for each color.
*/

int	ft_parse_floor_colors(t_env *env, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && (ft_isalpha(tmp[i]) || tmp[i] == ' '))
		i++;
	env->colors.floor_red = ft_int_ternaire(ft_isdigit(tmp[i]),
			ft_atoi(&(tmp[i])), -1);
	while (tmp[i] && (ft_isdigit(tmp[i]) || tmp[i] == ' '))
		i++;
	while (tmp[i] && (tmp[i] == ',' || tmp[i] == ' '))
		i++;
	env->colors.floor_green = ft_int_ternaire(ft_isdigit(tmp[i]),
			ft_atoi(&(tmp[i])), -1);
	while (tmp[i] && (ft_isdigit(tmp[i]) || tmp[i] == ' '))
		i++;
	while (tmp[i] && (tmp[i] == ',' || tmp[i] == ' '))
		i++;
	env->colors.floor_blue = ft_int_ternaire(ft_isdigit(tmp[i]),
			ft_atoi(&(tmp[i])), -1);
	if (!(ft_control_color_two(env, tmp, i, 'F')))
		return (0);
	return (1);
}

int	ft_parse_sky_colors(t_env *env, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && (ft_isalpha(tmp[i]) || tmp[i] == ' '))
		i++;
	env->colors.sky_red = ft_int_ternaire(ft_isdigit(tmp[i]),
			ft_atoi(&(tmp[i])), -1);
	while (tmp[i] && (ft_isdigit(tmp[i]) || tmp[i] == ' '))
		i++;
	while (tmp[i] && (tmp[i] == ',' || tmp[i] == ' '))
		i++;
	env->colors.sky_green = ft_int_ternaire(ft_isdigit(tmp[i]),
			ft_atoi(&(tmp[i])), -1);
	while (tmp[i] && (ft_isdigit(tmp[i]) || tmp[i] == ' '))
		i++;
	while (tmp[i] && (tmp[i] == ',' || tmp[i] == ' '))
		i++;
	env->colors.sky_blue = ft_int_ternaire(ft_isdigit(tmp[i]),
			ft_atoi(&(tmp[i])), -1);
	if (!(ft_control_color_two(env, tmp, i, 'S')))
		return (0);
	return (1);
}

int	ft_parse_info(t_env *env, char *line)
{
	int	i;

	i = -1;
	env->mlx->w.width = 800;
	env->mlx->w.height = 500;
	ft_control_resolution(env);
	while (line[++i] != '\0')
	{
		if (line[i] == 'F' && line[i + 1] == ' ')
		{
			if (!ft_parse_floor_colors(env, line))
				return (0);
			env->error.floor_color += 1;
		}
		if (line[i] == 'C' && line[i + 1] == ' ')
		{
			if (!ft_parse_sky_colors(env, line))
				return (0);
			env->error.ceilling_color += 1;
		}
	}
	return (1);
}
