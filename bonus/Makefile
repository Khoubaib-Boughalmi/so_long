# NAME 			= so_long
# CFLAGS 			= -Wall -Wextra -Werror
# CC 				= cc
# RM 				= rm -f
# LIBFT			= libft/libft.a
# PRINTF			= ft_printf/libftprintf.a

# SRCS_BONUS= render_map_bonus.c \
# 			map_check_bonus.c \
# 			map_to_matrix_bonus.c \
# 			utils_bonus.c \
# 			so_long_bonus.c \
# 			positions_bonus.c \
# 			is_enemy_bonus.c \
# 			map_metadata_bonus.c \
# 			check_path_bonus.c \
# 			key_hook_bonus.c \
# 			exit_bonus.c \
# 			initial_position_bonus.c \
# 			initial_render_map_bonus.c \
# 			initiate_img_vars_bonus.c \
# 			is_collectable_enemy_bonus.c 

# B_OBJ 		= ${SRCS_BONUS:.c=.o}

# %.o: %.c
# 	${CC} -c $< -o $@ ${CFLAGS}

# ${NAME}: ${LIBFT} ${PRINTF} ${B_OBJ}
# 		${CC} ${CFLAGS} ${B_OBJ} ft_printf/libftprintf.a libft/libft.a -lmlx -framework OpenGL -framework AppKit -o ${NAME}

# ${PRINTF}:	
# 		make all -C ft_printf

# ${LIBFT}:	
# 		make all -C libft
# 		make bonus -C libft

# all:	${NAME} 

# clean:	
# 		${RM} ${B_OBJ}
# 		make fclean -C libft
# 		make fclean -C ft_printf
	
# fclean:	clean
# 		${RM} ${NAME}

# re:	fclean all

# bonus:	${name}	${B_OBJ}
# 	${AR} ${NAME} ${B_OBJ}

# .PHONY:	all clean fclean re bonus

# #gcc render_map.c map_check.c map_to_matrix.c utils.c so_long.c ft_printf/*.c libft/*.c positions.c is_enemy.c map_metadata.c check_path.c key_hook.c exit.c initial_position.c initial_render_map.c initiate_img_vars.c is_collectable_enemy.c  -lmlx -framework OpenGL -framework AppKit;