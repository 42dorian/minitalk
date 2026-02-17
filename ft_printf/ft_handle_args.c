/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:16:55 by dabdulla          #+#    #+#             */
/*   Updated: 2025/10/21 20:40:23 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = s;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putnbr(long n, int base)
{
	int		len;
	char	*base_chars;

	len = 0;
	base_chars = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	if (n >= base)
		len += ft_putnbr(n / base, base);
	len += write(1, &base_chars[n % base], 1);
	return (len);
}

int	ft_putnbr_caps(long n, int base)
{
	int		len;
	char	*base_chars;

	len = 0;
	base_chars = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	if (n >= base)
		len += ft_putnbr_caps(n / base, base);
	len += write(1, &base_chars[n % base], 1);
	return (len);
}
