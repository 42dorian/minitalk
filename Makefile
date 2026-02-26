SOURCES = server.c client.c server_bonus.c client_bonus.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFTPRINTF = ft_printf/libftprintf.a

all: server client
bonus: server_bonus client_bonus

server: server.o $(LIBFTPRINTF)
	$(CC) -o $@ $^

client: client.o $(LIBFTPRINTF)
	$(CC) -o $@ $^

server_bonus: server_bonus.o $(LIBFTPRINTF)
	$(CC) -o $@ $^

client_bonus: client_bonus.o $(LIBFTPRINTF)
	$(CC) -o $@ $^

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	$(MAKE) -C ft_printf

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f server client
	rm -f server_bonus client_bonus
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all bonus clean fclean re