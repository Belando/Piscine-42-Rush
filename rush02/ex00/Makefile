NAME = rush-02
SRCS = dict_helpers.c dict.c err_handlers.c rush-02.c utils.c number_comp.c
DEPS = rush02.h
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(SRCS) $(FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean