/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:16:06 by dabdulla          #+#    #+#             */
/*   Updated: 2025/10/21 20:41:14 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid(const char c)
{
	int		i;
	char	*valid_chars;

	valid_chars = "cspdiuxX%";
	i = 0;
	while (valid_chars[i])
	{
		if (c == valid_chars[i])
			return (1);
		i++;
	}
	return (0);
}

int	handle_args(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	if (c == '%')
		count += ft_putchar('%');
	if (c == 'i' || c == 'd')
		count += ft_putnbr((long)va_arg(args, int), 10);
	if (c == 'x')
		count += ft_putnbr(va_arg(args, unsigned int), 16);
	if (c == 'X')
		count += ft_putnbr_caps(va_arg(args, unsigned int), 16);
	if (c == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	if (c == 'u')
		count += ft_printf_uint(va_arg(args, unsigned int), 10);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (0);
	va_start(args, format);
	if (format[i] == '%' && !(format[i + 1]))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && is_valid(format[i + 1]))
			len += handle_args(format[++i], args);
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
