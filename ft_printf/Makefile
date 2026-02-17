NAME = libftprintf.a

CXX = cc

SRC = ft_printf.c \
		ft_handle_args.c \
		ft_handle_ptr.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CREATION = ar -rc

all: $(NAME)

$(NAME): $(OBJ)
	@$(CREATION) $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
