SRCS =	srcs/ft_create_image.c \
		srcs/ft_draw_image.c \
		srcs/ft_draw_utils.c \
		srcs/ft_init_env.c \
		srcs/ft_move.c \
		srcs/ft_parse_info.c \
		srcs/ft_parse_map.c \
		srcs/ft_cub3d.c \
		srcs/utils_and_control.c \
		srcs/ft_parser.c \
		srcs/ft_set_variable.c \
		srcs/ft_quit.c \


NAME = cub3D

CC		= clang

CFLAGS	= -Wall -Wextra -Werror -g

all: 		${NAME}
			@echo "COMPILED"

${NAME}:	${SRCS}
			@make -C libft
			@make -C minilibx-linux
			${CC} ${SRCS} ${CFLAGS} -Ofast -g -I includes -L./libft -lft -L./minilibx-linux -lmlx -lXext -lX11 -lm -o ${NAME}
%.o: %.c
			@echo "${G}[OK]${NC}	${Y}Compiling:${NC}" $<
			${CC} $< $(CFLAGS) -I libft -I includes -c -o $@

clean:
			${MAKE} clean -C libft
			${MAKE} clean -C minilibx-linux

fclean:		clean
			${MAKE} fclean -C libft
			${MAKE} fclean -C bonus
			rm -f ${NAME}

re:			fclean all

bonus:		
			@make -C libft
			@make -C minilibx-linux
			@make -C bonus

.PHONY:		all fclean clean re bonus
