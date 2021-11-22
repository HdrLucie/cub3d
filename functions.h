/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:11:26 by hlucie            #+#    #+#             */
/*   Updated: 2021/06/21 14:45:59 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "include.h"

char			**ft_parser(t_env *env, char *path);
int				ft_parse_resolution(t_env *env, char c, char *tmp);
int				ft_parse_floor_colors(t_env *env, char *tmp);
int				ft_parse_sky_colors(t_env *env, char *tmp);
int				ft_parse_info(t_env *env, char *line);
char			**ft_parse_map(t_env *env, char *line, char **map, int fd);
void			ft_size_map(char *path, t_env *env);
char			*ft_sort_info(t_env *env, int fd);
void			ft_control_resolution(t_env *env);

int				ft_create_texture(char *side, char *s, t_texture *texture,
					t_env *env);
int				ft_init_texture(t_env *env, char *line, int h);

void			ft_my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				ft_draw_frame(t_env *env);
void			ft_draw_roof(t_env *env);
void			ft_calc_wall_size(t_draw_tools *draw_tools, t_env *env);
void			ft_find_wall_texture(t_draw_tools *draw_tools);
void			ft_find_a_wall(t_draw_tools *draw_tools, t_env *env);
void			ft_init_draw_tools(t_draw_tools *draw_tools, t_env *env, int x);
void			ft_texture_stripe(t_env *env, int x, t_draw_tools *draw_tools);

void			ft_control_parse(t_env *env, char **line);
int				ft_control_map(t_env *env);
void			ft_print_info(t_env *env);
void			ft_quit(t_env *env);
void			ft_free_and_quit(t_env *env);
void			ft_print_error(char c, t_env *env);
void			ft_free(char **ptr);

void			ft_init_flag_texture(t_env *env);
int				ft_deal_key(int keycode, t_env *env);

t_mlx			*ft_mlx_init(void);
t_data			*ft_init_img(t_env *env);
int				ft_init(t_env *env, char *path);
void			ft_control_extension(char *extension);

int				create_trgb(int t, int r, int g, int b);
void			ft_save(t_env *env);
void			fill_char_tab_with_int(int number, char *tab);
void			file_header(t_env *env, char *buffer);
void			info_header(t_env *env, char *buffer);
void			fill_bitmap(t_env *env, int fd);

void			set_data_texture(t_env *env);
void			set_error_flag(t_env *env);
void			ft_set_variables(t_env *env);
int				ft_control_color(t_env *env, char c);
int				ft_control_color_two(t_env *env, char *tmp, int i, char c);

#endif
