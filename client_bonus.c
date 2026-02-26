/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 23:30:08 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/26 11:21:08 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_server_signal;

long	ft_atoi(const char *nptr)
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
	g_server_signal = 1;
	if (sig == SIGUSR2)
		ft_printf("End Message received!\n");
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

int	valid_pid(char *s)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	pid = ft_atoi(s);
	if ((pid < 0) || (pid > INT_MAX))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa_c;
	int					pid;
	char				*msg;
	int					i;

	if (argc != 3)
		return (ft_printf("2 arguments required!\n"), 0);
	sa_c.sa_handler = client_handler;
	sa_c.sa_flags = 0;
	sigemptyset(&sa_c.sa_mask);
	if (sigaction(SIGUSR1, &sa_c, NULL) == -1)
		return (ft_printf("Sigaction Error"), -1);
	if (sigaction(SIGUSR2, &sa_c, NULL) == -1)
		return (ft_printf("Sigaction Error"), -1);
	msg = argv[2];
	if (!valid_pid(argv[1]))
		return (ft_printf("Invalid PID\n"), -1);
	i = 0;
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		return (ft_printf("Wrong PID\n") - 1);
	while (msg[i])
		send_char(pid, msg[i++]);
	return (send_char(pid, '\n'), send_char(pid, '\0'), 0);
}
