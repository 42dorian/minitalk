/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 23:30:08 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/22 14:38:20 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

static int	g_server_signal;

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	value;

	value = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
		if (nptr[i] == '+')
			return (0);
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = value * 10 + nptr[i] - 48;
		i++;
	}
	return (value * sign);
}

void	client_handler(int sig)
{
	(void)sig;
	g_server_signal = 1;
}

void	send_char(int pid, char c)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		g_server_signal = 0;
		if ((c >> bits) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bits--;
		while (g_server_signal == 0)
			pause();
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*msg;
	int		i;

	if (argc != 3)
		return (0);
	signal(SIGUSR1, client_handler);
	signal(SIGUSR2, client_handler);
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	i = 0;
	while (msg[i])
		send_char(pid, msg[i++]);
	send_char(pid, '\n');
	return (0);
}
