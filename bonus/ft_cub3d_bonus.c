/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:04:19 by hlucie            #+#    #+#             */
/*   Updated: 2021/07/06 18:46:17 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_bonus.h"

int	ft_resize_window(void *env)
{
	ft_draw_frame(env);
	return (0);
}

int	ft_deal_cross(t_env *env)
{
	ft_free_and_quit(env);
	return (1);
}

void	ft_control_extension(char *extension)
{
	int		i;

	i = ft_strlen(extension) - 1;
	if (i > 4)
	{
		if (extension[i] != 'b' || extension[i - 1] != 'u'
			|| extension[i - 2] != 'c'
			|| extension[i - 3] != '.')
		{
			printf("ERROR\nWRONG PATH\n");
			exit(0);
		}
	}
	else
	{
		printf("ERROR\nWRONG PATH\n");
		exit(0);
	}
}

void	ft_draw(t_env *env)
{
	ft_draw_frame(env);
	mlx_hook(env->mlx->win_ptr, 2, 1L << 0, ft_key_pressed, (env));
	mlx_hook(env->mlx->win_ptr, 3, 1L << 1, ft_key_released, (env));
	mlx_hook(env->mlx->win_ptr, 33, 1L << 0, ft_deal_cross, (env));
	mlx_hook(env->mlx->win_ptr, 9, 1L << 21, ft_resize_window, (void *)env);
	mlx_loop_hook(env->mlx->mlx_ptr, ft_draw_frame, (env));
	mlx_loop(env->mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	char	*path;

	path = argv[1];
	if (argc != 2)
	{
		printf("ERROR\nWRONG ARGUMENT\n");
		return (0);
	}
	ft_control_extension(path);
	env = malloc(sizeof(t_env));
	if (env == NULL)
		ft_free_and_quit(env);
	if (!ft_init(env, path))
		ft_free_and_quit(env);
	ft_draw(env);
	return (0);
}
