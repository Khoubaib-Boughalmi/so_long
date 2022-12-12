NAME 			= libft.a
CFLAGS 		= -Wall -Wextra -Werror
CC 				= gcc
AR 				= ar rcs
RM 				= rm -f

SRCS=   so_long.c \

# SRCS_BONUS= 

OBJ 	        = ${SRCS:.c=.o}
B_OBJ 		= ${SRCS_BONUS:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all:	${NAME}

clean:	
		${RM} ${OBJ} ${B_OBJ}
	
fclean:	clean
		${RM} ${NAME}

re:	fclean all

bonus:	${name}	${B_OBJ}
	${AR} ${NAME} ${B_OBJ}

.PHONY:	all clean fclean re bonus