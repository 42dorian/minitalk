/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:36:24 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/25 17:52:14 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_SOURCE
# define _DEFAULT_SOURCE

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <signal.h>

void	handle_signal(int signal, siginfo_t *info, void *context);
long	ft_atoi(const char *nptr);
void	client_handler(int sig);
void	send_char(int pid, char c);
int		valid_pid(char *s);

#endif