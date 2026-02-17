SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFTPRINTF = ft_printf/libftprintf.a

all: server client
bonus: all

server: server.o $(LIBFTPRINTF)
	$(CC) -o $@ $^

client: client.o $(LIBFTPRINTF)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	$(MAKE) -C ft_printf

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f server client
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all bonus clean fclean re