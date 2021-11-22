/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:39:39 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/21 00:46:44 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions.h"

/*
** In that file, I recover my path's textures and I stock them.
** If i find "NO", "SO", "WE", "EA", I will check the path, and 
** extract data of my image. I check if I have 4 textures and not more.
*/

int	ft_init_texture(t_env *env, char *line, int h)
{
	int		j;
	char	*t[4];

	t[0] = "NO";
	t[1] = "SO";
	t[2] = "WE";
	t[3] = "EA";
	j = -1;
	while (line[h] && line[h] == ' ')
		h++;
	while (++j < 4)
	{
		if (!(ft_strncmp(&(line[h]), t[j], ft_strlen(t[j]))))
		{
			env->error.flag_texture[j] += 1;
			if (!(ft_create_texture(t[j], line, &(env->texture[j]), env)))
				return (0);
			return (1);
		}
	}
	return (1);
}

int	ft_create_texture(char *side, char *s, t_texture *texture, t_env *env)
{
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	if (env->nb_textures > 3 || ft_strncmp(s, side, ft_strlen(side)))
		return (0);
	i += ft_strlen(side);
	while (s[i] && s[i] == ' ')
		i++;
	path = &(s[i]);
	while (s[i] && s[i] != ' ')
		i++;
	s[i] = '\0';
	if (texture->data.img != NULL)
		return (0);
	texture->data.img = mlx_xpm_file_to_image(env->mlx->mlx_ptr,
			path, &(texture->width), &(texture->height));
	if (texture->data.img == NULL)
		return (0);
	texture->data.adress = mlx_get_data_addr(texture->data.img,
			&(texture->data.bpp), &(texture->data.line_lgt),
			&(texture->data.endian));
	env->nb_textures++;
	return (1);
}
