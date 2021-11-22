BONUS =	ft_create_image_bonus.c \
		ft_draw_image_bonus.c \
		ft_draw_sprite_bonus.c \
		ft_draw_utils_bonus.c \
		ft_init_env_bonus.c \
		ft_move_bonus.c \
		ft_parse_info_bonus.c \
		ft_parse_map_bonus.c \
		ft_cub3d_bonus.c \
		utils_and_control_bonus.c \
		ft_sprite_utils_bonus.c \
		ft_parser_bonus.c \
		ft_set_variable_bonus.c \
		ft_hud_bonus.c \
		ft_check_player_bonus.c \
		ft_init_mlx_bonus.c \
		ft_weapon_bonus.c \
		ft_second_move_bonus.c \
		ft_mini_map_bonus.c \
		ft_manage_error_bonus.c \
		ft_manage_event_bonus.c

NAME = cub3d_bonus

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

all: 		${NAME}
			@echo "COMPILED"

${NAME}:	${BONUS}
			${CC} ${BONUS} ${CFLAGS} -Ofast -I includes -L../libft -lft -L../minilibx-linux -lmlx -lXext -lX11 -lm -o ${NAME}

%.o: %.c
			@echo "${G}[OK]${NC}	${Y}Compiling:${NC}" $<
			${CC} $< $(CFLAGS) -I libft -I includes -c -o $@

fclean:	
			rm -f ${NAME}

re:			fclean all

.PHONY:		all fclean re

