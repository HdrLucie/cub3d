/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:44:52 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 00:22:52 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions.h"

int	ft_check_texture(char *line, int fd, t_env *env, int i)
{
	int	h;

	h = 0;
	if (ft_is_in_str("NSEW", line[i]))
	{
		if (!ft_init_texture(env, &(line[i]), h))
		{
			get_next_line(fd, &line, 0);
			ft_free(&line);
			ft_print_error('T', env);
		}
		return (1);
	}
	return (0);
}

/*
** Here I check info of file, if check_texture is valid.
** If i find F or C, I'm going to parse color's informations.
** ELse, if I don't find it, I free and quit.
*/

void	ft_detect_info(char *line, int fd, t_env *env, int i)
{
	int	h;

	h = -1;
	if (!(ft_check_texture(line, fd, env, i)))
	{
		if (ft_is_in_str("FC", line[i]))
		{
			if (!ft_parse_info(env, &(line[i])))
			{
				get_next_line(fd, &line, 0);
				ft_free(&line);
				ft_print_error('I', env);
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
	line = NULL;
}

/*
** Here, I parse my file. I read it while it not finish.
*/

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

/*
** In that function, I start to parse my map.
** First, I open my file .cub, if fd == -1, I free and quit.
** Second, I calculate the sie of my map.
** I initialize my texture.
** I parse informations of my file : colors and path's textures.
** I control that informatons with control_parse.
** I parse my map and I control if it's valid.
*/

char	**ft_parser(t_env *env, char *path)
{
	int		fd;
	char	*line;
	char	**map;

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
	env->texture = malloc(sizeof(t_texture) * 4);
	if (env->texture == NULL)
		ft_free_and_quit(env);
	set_data_texture(env);
	line = ft_sort_info(env, fd);
	ft_control_parse(env, &line);
	env->map = ft_parse_map(env, line, map, fd);
	ft_control_map(env);
	close(fd);
	return (env->map);
}
