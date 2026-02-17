/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:14:40 by dabdulla          #+#    #+#             */
/*   Updated: 2025/10/21 20:49:07 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long n, int base);
int	ft_putnbr_caps(long n, int base);
int	ft_print_ptr(void *pointer);
int	ft_printf_uint(unsigned long n, int base);
int	is_valid(const char c);
int	ft_strlen(char *s);
int	handle_args(const char c, va_list args);

#endif