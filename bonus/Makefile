NAME 			= so_long
CFLAGS 			= -Wall -Wextra -Werror
CC 				= gcc
AR 				= ar rcs
RM 				= rm -f

SRCS_BONUS= render_map.c \
			map_check.c \
			map_to_matrix.c \
			utils.c \
			so_long.c \
			ft_printf/*.c \
			libft/*.c \
			positions.c \
			is_enemy.c \
			map_metadata.c \
			check_path.c \
			key_hook.c \
			exit.c \
			initial_position.c \
			initial_render_map.c \
			initiate_img_vars.c \
			is_collectable_enemy.c

B_OBJ 		= ${SRCS_BONUS:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}: ${B_OBJ}
	${CC} ${CFLAGS} ${B_OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all:	${NAME}

print:	
		make all -C ft_printf
		
libft:	
		make all -C libft

clean:	
		${RM} ${OBJ} ${B_OBJ}
	
fclean:	clean
		${RM} ${NAME}

re:	fclean all

bonus:	${name}	${B_OBJ}
	${AR} ${NAME} ${B_OBJ}

.PHONY:	all clean fclean re bonus

#gcc render_map.c map_check.c map_to_matrix.c utils.c so_long.c ft_printf/*.c libft/*.c positions.c is_enemy.c map_metadata.c check_path.c key_hook.c exit.c initial_position.c initial_render_map.c initiate_img_vars.c is_collectable_enemy.c  -lmlx -framework OpenGL -framework AppKit;