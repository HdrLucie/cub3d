/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_error_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:47:11 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/20 01:50:34 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

int	ft_control_color_two(t_env *env, char *tmp, int i, char c)
{
	if (c == 'F')
	{
		while (tmp[i] && ft_isdigit(tmp[i]))
			i++;
		while (tmp[i] && tmp[i] == ' ')
			i++;
		if (tmp[i] || !(ft_control_color(env, 'F')))
			return (0);
	}
	else if (c == 'S')
	{
		while (tmp[i] && ft_isdigit(tmp[i]))
			i++;
		while (tmp[i] && tmp[i] == ' ')
			i++;
		if (tmp[i] || !(ft_control_color(env, 'S')))
			return (0);
	}
	return (1);
}

void	ft_control_sprite(t_env *env, char **line)
{
	if (env->error.flag_sprite[0] != 1 || env->error.flag_sprite[1] != 1
		|| env->error.flag_sprite[2] != 1 || env->error.flag_sprite[3] != 1
		|| env->error.flag_sprite[4] != 1)
	{
		get_next_line(-1, line, 0);
		ft_free(line);
		ft_print_error('S', env);
	}
}

void	ft_control_parse(t_env *env, char **line)
{
	if (env->error.flag_texture[0] != 1 || env->error.flag_texture[1] != 1
		|| env->error.flag_texture[2] != 1 || env->error.flag_texture[3] != 1)
	{
		get_next_line(-1, line, 0);
		ft_free(line);
		ft_print_error('T', env);
	}
	if (env->error.ceilling_color != 1 || env->error.floor_color != 1)
	{
		get_next_line(-1, line, 0);
		ft_free(line);
		ft_print_error('I', env);
	}
	ft_control_sprite(env, line);
}

void	ft_print_error(char c, t_env *env)
{
	if (c == 'T')
		printf("ERROR\nWRONG TEXTURE OR SPRITE PATH\n");
	if (c == 'M')
		printf("ERROR.\nWRONG MAP\n");
	if (c == 'P')
		printf("ERROR.\nWRONG POSITION.\n");
	else if (c == 'C')
		printf("ERROR\nWRONG CHARACTER\n");
	else if (c == 'I')
		printf("ERROR\nWRONG INFO : COLOR\n");
	else if (c == 'S')
		printf("ERROR\nWRONG SPRITE PATH\n");
	else if (c == 'A')
	{
		printf("ERROR\nWRONG SAVE ARGUMENT\n");
		exit(0);
	}
	ft_free_and_quit(env);
}
