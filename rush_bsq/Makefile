NAME = bsq
SRCS = bsq.c errors.c readmap.c ft_validate_map.c ft_find_square.c utils.c
DEPS = rushbsq.h
OBJS = ${SRC:.c=.o}
FLAGS = -Wall -Werror -Wextra

all:	${NAME}

${NAME}: ${OBJS}
	cc -o ${NAME} ${SRCS} -Iincludes ${FLAGS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean