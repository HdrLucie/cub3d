/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:40:02 by hlucie            #+#    #+#             */
/*   Updated: 2021/06/23 18:37:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"
# define BUFFER_SIZE 200

void	*ft_malloc_ultra(char *ptr, size_t size);
char	*ft_strdup_custom(char *s, char *str);
int		ft_fill_line(char **line, char *buffer, char **adress_pos);
int		get_next_line(int fd, char **line, int flag);
int		ft_read_next_line(char **line, char **buff_pos, int fd);
void	ft_free_plz(char **ptr);

#endif
