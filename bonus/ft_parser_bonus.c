/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:44:52 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:47:39 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

int	ft_detect_sprite(char *line, int fd, t_env *env, int i)
{
	int	h;

	h = -1;
	if (ft_is_in_str("ZTBIUR", line[i]))
	{
		if (!ft_sprite_path(env, &(line[i]), h))
		{
			get_next_line(fd, &line, 0);
			ft_free(&line);
			ft_print_error('S', env);
		}
		return (1);
	}
	else if (ft_is_in_str("FC", line[i]))
	{
		if (!ft_parse_info(env, &(line[i])))
		{
			get_next_line(fd, &line, 0);
			ft_free(&line);
			ft_print_error('I', env);
		}
		return (1);
	}
	return (0);
}

void	ft_detect_info(char *line, int fd, t_env *env, int i)
{
	int	h;

	h = -1;
	if (!(ft_detect_sprite(line, fd, env, i)))
	{
		if (ft_is_in_str("NSEW", line[i]))
		{
			if (!ft_init_texture(env, &(line[i]), h))
			{
				get_next_line(fd, &line, 0);
				ft_free(&line);
				ft_print_error('T', env);
			}
		}
		else if (line[i])
		{
			get_next_line(fd, &line, 0);
			ft_free(&line);
			ft_print_error('I', env);
		}
	}
	ft_free(&line);
}

char	*ft_sort_info(t_env *env, int fd)
{
	int		i;
	int		ret;
	char	*line;

	i = 0;
	ret = 1;
	ft_init_flag_texture(env);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line, 1);
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '1')
			ret = 0;
		else
			ft_detect_info(line, fd, env, i);
		i = 0;
	}
	return (line);
}

void	ft_set_parser_var(t_env *env)
{
	env->texture = malloc(sizeof(t_texture) * 5);
	if (!(env->texture))
		ft_free_and_quit(env);
	env->sprite_text = malloc(sizeof(t_texture) * 7);
	if (!(env->sprite_text))
		ft_free_and_quit(env);
	set_data_texture(env);
	set_data_sprite(env);
}

char	**ft_parser(t_env *env, char *path)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	env->size_map = 0;
	env->path = path;
	map = NULL;
	set_error_flag(env);
	fd = open(env->path, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\nWRONG FILE\n");
		ft_free_and_quit(env);
	}
	ft_size_map(path, env);
	ft_set_parser_var(env);
	line = ft_sort_info(env, fd);
	ft_control_parse(env, &line);
	env->map = ft_parse_map(env, line, map, fd);
	ft_control_map(env);
	close(fd);
	return (env->map);
}
