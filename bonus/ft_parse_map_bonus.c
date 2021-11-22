/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:18:48 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 02:35:06 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

int	ft_calc_line(t_env *env, int fd, char *line, int i)
{
	int	ret;
	int	flag;

	flag = 0;
	ret = get_next_line(fd, &line, 1);
	while (ret > 0)
	{
		if (!flag)
		{
			while (line[i] && line[i] == ' ')
				i++;
			if (ft_isdigit(line[i]))
				flag = 1;
		}
		if (flag)
			env->size_map++;
		i = 0;
		ft_free(&line);
		ret = get_next_line(fd, &line, 1);
	}
	ft_free(&line);
	return (ret);
}

void	ft_size_map(char *path, t_env *env)
{
	char	*line;
	int		ret;
	int		i;
	int		fd;

	i = 0;
	line = NULL;
	fd = open(path, O_RDONLY);
	ret = ft_calc_line(env, fd, line, i);
	if (ret == -1)
	{
		printf("ERROR\nWRONG FILE\n");
		ft_free_and_quit(env);
	}
	env->size_map++;
	if (env->size_map == 1)
		ft_print_error('M', env);
	close(fd);
}

char	**ft_parse_map(t_env *env, char *line, char **map, int fd)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = -1;
	ret = 1;
	while (line[i] == ' ')
		i++;
	map = malloc(sizeof(char *) * (env->size_map + 1));
	if (!(map))
		ft_free_and_quit(env);
	while (++j < env->size_map)
	{
		map[j] = line;
		get_next_line(fd, &line, 1);
	}
	map[j] = line;
	return (map);
}

/*
** Here I control my map. First I check if my map isn't separated. 
** I browse my map, if I find a character that isn't NSEW01, I free and quit.
** I set a flag when I found my position (NSEW)> I'm going to use that flag 
** to check if I have one or more positions. 
** If i find a 0, if check numbers/ltters around it.
** If itn't 01234567NSEW, it's not valid. So I free and quit. 
*/

int	ft_browse_map(size_t i, int j, t_env *env)
{
	if (env->map[j][i] == '\0' && env->map[j + 1][i] != '\0')
		ft_print_error('M', env);
	while (env->map[j][i] != '\0' && env->map[j][i] != ' ')
	{
		if (!(ft_is_in_str("NSEW10234567", env->map[j][i])))
			ft_print_error('M', env);
		if (ft_is_in_str("NSEW", env->map[j][i]))
			env->error.counter_pos++;
		if (env->map[j][i] == '0' || env->map[j][i] == '2'
			|| env->map[j][i] == '3' || env->map[j][i] == '4'
			|| env->map[j][i] == '5' || env->map[j][i] == '6'
			|| env->map[j][i] == '7')
		{
			if (j == 0 || i == 0 || i == ft_strlen(env->map[j]) - 1
				|| j == env->size_map - 1 || ft_strlen(env->map[j + 1]) < i)
				ft_print_error('M', env);
			if (!(ft_is_in_str("10234567NSEW", env->map[j][i - 1]))
				|| !(ft_is_in_str("10234567NSEW", env->map[j][i + 1]))
				|| !(ft_is_in_str("10234567NSEW", env->map[j - 1][i]))
				|| !(ft_is_in_str("10234567NSEW", env->map[j + 1][i])))
				ft_print_error('M', env);
		}
		i++;
	}
	return (i);
}

int	ft_control_map(t_env *env)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	env->error.counter_pos = 0;
	while (j < env->size_map)
	{
		while (env->map[j][i] && env->map[j][i] == ' ')
			i++;
		i = ft_browse_map(i, j, env);
		while (env->map[j][i] && env->map[j][i] == ' ')
			i++;
		i = 0;
		j++;
	}
	if (env->error.counter_pos != 1)
		ft_print_error('P', env);
	return (1);
}
