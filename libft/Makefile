SRC = ft_strlen.c ft_atoi.c ft_strdup.c ft_strncmp.c ft_split.c ft_substr.c ft_strjoin.c ft_strchr.c ft_isalpha.c \
ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strrchr.c \
ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlcat.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memmove.c ft_calloc.c ft_strtrim.c ft_strmapi.c get_next_line.c get_next_line_utils.c ft_is_in_str.c \
ft_int_ternaire.c ft_float_ternaire.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c

OBJS = ${SRC:.c=.o}
BONUS_OBJS = $(BONUS:.c=.o)
CFLAGS =  -g -Wall -Wextra -Werror

#LDFLAGS = -shared
CC = gcc
NAME = libft.a

#SONAME = libft.so

%.o : %.c
			${CC} ${CFLAGS} -I includes -c $< -o $@

all :		${NAME} ${OBJS}
			@echo "Compiled"
#so :        ${SONAME} 

${NAME} : 	${OBJS}
			ar rc $@ $^

#$(SONAME):  $(OBJS)
		#${CC} ${LDFLAGS} -o $@ $^

clean :
			rm -f ${OBJS} ${BONUS_OBJS}
fclean :	clean
			rm -f ${NAME}
re :		fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY : all clean fclean re bonus
