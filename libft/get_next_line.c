/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:31:33 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/08 13:09:21 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_next_line(char **line, char **buff_pos, int fd)
{
	char	*buffer;
	int		flag;

	buffer = NULL;
	flag = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!(buffer))
		return (-1);
	flag = read(fd, buffer, BUFFER_SIZE);
	while (flag > 0)
	{
		ft_free_plz(buff_pos);
		buffer[flag] = '\0';
		flag = ft_fill_line(line, buffer, buff_pos);
		if (flag == 1)
		{
			ft_free_plz(&buffer);
			return (flag);
		}
		flag = read(fd, buffer, BUFFER_SIZE);
	}
	ft_free_plz(&buffer);
	return (flag);
}

int	ft_fill_line(char **line, char *buffer, char **adress_pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && i < BUFFER_SIZE && buffer[i] != '\n')
		i++;
	*line = ft_malloc_ultra(*line, sizeof(char) * i);
	if (!(*line))
		return (-1);
	j = ft_strlen(*line);
	i = 0;
	while (buffer[i] != '\0' && i < BUFFER_SIZE && buffer[i] != '\n')
		(*line)[j++] = buffer[i++];
	(*line)[j] = '\0';
	if (buffer[i] == '\n')
	{
		*adress_pos = ft_strdup_custom(&(buffer[i + 1]), *adress_pos);
		return (1);
	}
	return (0);
}

int	free_buffer(int flg, char *buffer)
{
	if (!flg)
	{
		ft_free_plz(&buffer);
		return (1);
	}
	return (0);
}

int	ft_check_line(char **line)
{
	if (!(*line))
	{
		*line = ft_malloc_ultra(*line, 1);
		if (!(*line))
			return (-1);
		**line = '\0';
	}
	return (0);
}

int	get_next_line(int fd, char **line, int flg)
{
	int			flag;
	static char	*buff_pos = NULL;

	flag = 0;
	if (free_buffer(flg, buff_pos))
		return (0);
	if (line)
		*line = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (buff_pos && buff_pos[0] != '\0')
	{
		flag = ft_fill_line(line, buff_pos, &buff_pos);
		if (flag)
			return (flag);
		ft_free_plz(&buff_pos);
		buff_pos = NULL;
	}
	flag = ft_read_next_line(line, &buff_pos, fd);
	if (flag)
		return (flag);
	ft_free_plz(&buff_pos);
	ft_check_line(line);
	return (0);
}
