/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:11:26 by hlucie            #+#    #+#             */
/*   Updated: 2021/06/21 14:49:48 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_BONUS_H
# define FUNCTIONS_BONUS_H

# include "include_bonus.h"

int				ft_init(t_env *env, char *path);
void			ft_set_variables(t_env *env);
t_mlx			*ft_mlx_init(void);
t_data			*ft_init_img(t_env *env);
int				ft_init_texture(t_env *env, char *line, int h);
void			ft_init_draw_tools(t_draw_tools *draw_tools, t_env *env, int x);
void			ft_init_flag_texture(t_env *env);
t_s_tools		*ft_init_sprite_tools(void);
t_sprite		*ft_init_sprite(t_env *env);
int				ft_create_texture(char *side, char *s, t_texture *texture,
					t_env *env);
void			set_data_texture(t_env *env);

char			**ft_parser(t_env *env, char *path);
int				ft_parse_resolution(t_env *env, char c, char *tmp);
int				ft_parse_floor_colors(t_env *env, char c, char *tmp);
int				ft_parse_sky_colors(t_env *env, char c, char *tmp);
int				ft_parse_info(t_env *env, char *line);
char			**ft_parse_map(t_env *env, char *line, char **map, int fd);
void			ft_size_map(char *path, t_env *env);
char			*ft_sort_info(t_env *env, int fd);
void			ft_control_resolution(t_env *env);

void			ft_go_right(t_env *env);
void			ft_go_backward(t_env *env);
void			ft_go_forward(t_env *env);
void			ft_go_left(t_env *env);
void			ft_move_camera(t_env *env);

int				ft_deal_key(t_env *env);
int				ft_key_pressed(int keycode, t_env *env);
int				ft_key_released(int keycode, t_env *env);
void			ft_set_move_var(t_env *env);

void			set_error_flag(t_env *env);
void			ft_control_extension(char *extension);
int				ft_control_color_two(t_env *env, char *tmp, int i, char c);
int				ft_control_color(t_env *env, char c);
void			ft_control_parse(t_env *env, char **line);
int				ft_control_map(t_env *env);
void			ft_print_info(t_env *env);
void			ft_quit(t_env *env);
void			ft_free_and_quit(t_env *env);
void			ft_print_error(char c, t_env *env);
void			ft_free(char **ptr);

int				create_sprite(char *side, char *s,
					t_texture *sprite, t_env *env);
int				ft_sprite_path(t_env *env, char *line, int h);
void			set_data_sprite(t_env *env);

int				create_trgb(int t, int r, int g, int b);
void			ft_my_mlx_pixel_put(t_env *env, int x, int y, int color);

int				ft_draw_frame(t_env *env);
void			ft_draw_roof(t_env *env);
void			ft_calc_wall_size(t_draw_tools *draw_tools, t_env *env);
void			ft_find_wall_texture(t_draw_tools *draw_tools);
void			ft_find_a_wall(t_draw_tools *draw_tools, t_env *env);
void			ft_texture_stripe(t_env *env, int x, t_draw_tools *draw_tools);

t_sprite		*ft_calc_nb_sprite(t_env *env);
void			ft_find_a_sprite(t_env *env);
void			ft_draw_sprite(t_env *env);
void			ft_order_sprite(t_env *env);
void			ft_init_s_tools(t_env *env);
void			ft_draw_stripe(t_env *env, int index);

t_texture		*ft_create_HUD(t_env *env);
void			ft_draw_pdv(t_env *env);
void			ft_init_hud_tools(t_hud_tools *hud_tools);
t_texture		*ft_game_over_text(t_env *env);
void			ft_draw_end(t_env *env);

t_event			*ft_init_event(void);
void			ft_check_var_player(t_env *env);
void			ft_bottles_effects(t_env *env);
void			ft_sprites_effects(t_env *env);

t_texture		*ft_create_hand_text(t_env *env);
void			ft_draw_hand(t_env *env);
void			ft_hit_hand(t_env *env);

void			ft_draw_mini_map(t_env *env);
void			ft_calcul_mini_map(t_env *env);
void			ft_animation_door(t_env *env);
void			ft_draw_door(t_env *env);
void			ft_draw_dead_ennemy(t_env *env);
void			ft_hit_ennemy(t_env *env);

#endif
