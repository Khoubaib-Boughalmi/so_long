NAME 			= so_long
CFLAGS 			= -Wall -Wextra -Werror
CC 				= cc
RM 				= rm -f
LIBFT			= libft/libft.a
PRINTF			= libft/ft_printf/libftprintf.a

SRCS_BONUS= ./bonus/render_map_bonus.c \
			./bonus/map_check_bonus.c \
			./bonus/map_to_matrix_bonus.c \
			./bonus/utils_bonus.c \
			./bonus/so_long_bonus.c \
			./bonus/positions_bonus.c \
			./bonus/is_enemy_bonus.c \
			./bonus/map_metadata_bonus.c \
			./bonus/check_path_bonus.c \
			./bonus/key_hook_bonus.c \
			./bonus/exit_bonus.c \
			./bonus/initial_position_bonus.c \
			./bonus/initial_render_map_bonus.c \
			./bonus/initiate_img_vars_bonus.c \
			./bonus/is_collectable_enemy_bonus.c \
			./bonus/animated_components.c 

SRCS_MAND= 	./mandatory/render_map.c \
			./mandatory/map_check.c \
			./mandatory/map_to_matrix.c \
			./mandatory/utils.c \
			./mandatory/so_long.c \
			./mandatory/positions.c \
			./mandatory/map_metadata.c \
			./mandatory/check_path.c \
			./mandatory/key_hook.c \
			./mandatory/exit.c \
			./mandatory/initial_position.c \

M_OBJ 		= ${SRCS_MAND:.c=.o}
B_OBJ 		= ${SRCS_BONUS:.c=.o}

%.o: %.c
	${CC} -c $< -o $@ ${CFLAGS}

${NAME}: ${LIBFT} ${PRINTF} ${M_OBJ}
		${CC} ${CFLAGS} ${M_OBJ} libft/ft_printf/libftprintf.a libft/libft.a -lmlx -framework OpenGL -framework AppKit -o ${NAME}

bonus: fclean ${LIBFT} ${PRINTF} ${B_OBJ}
		${CC} ${CFLAGS} ${B_OBJ} libft/ft_printf/libftprintf.a libft/libft.a -lmlx -framework OpenGL -framework AppKit -o ${NAME}


${PRINTF}:	
		make all -C libft/ft_printf

${LIBFT}:	
		make all -C libft
		make bonus -C libft

all:	${NAME} 

clean:	
		${RM} ${B_OBJ} ${M_OBJ} 
		make fclean -C libft
		make fclean -C libft/ft_printf
	
fclean:	clean
		${RM} ${NAME}

re:	fclean all


.PHONY:	all clean fclean re bonus


#//gcc render_map_bonus.c map_check_bonus.c map_to_matrix_bonus.c utils_bonus.c so_long_bonus.c ../ft_printf/*_bonus.c ../libft/*_bonus.c positions_bonus.c is_enemy_bonus.c map_metadata_bonus.c check_path_bonus.c key_hook_bonus.c exit_bonus.c initial_position_bonus.c initial_render_map_bonus.c initiate_img_vars_bonus.c is_collectable_enemy_bonus.c  -lmlx -framework OpenGL -framework AppKit;