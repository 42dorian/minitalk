/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:37:30 by dabdulla          #+#    #+#             */
/*   Updated: 2025/10/21 20:40:26 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_uint(unsigned long n, int base)
{
	char	buffer[sizeof(long) * 2];
	char	*base_chars;
	int		len;
	int		i;

	i = sizeof(buffer);
	len = 0;
	buffer[i] = '\0';
	base_chars = "0123456789abcdef";
	if (n == 0)
		buffer[--i] = '0';
	while (n > 0)
	{
		buffer[--i] = base_chars[n % base];
		n /= base;
	}
	while (buffer[i])
	{
		len += write(1, &buffer[i], 1);
		i++;
	}
	return (len);
}

int	ft_print_ptr(void *pointer)
{
	unsigned long	address;
	int				len;

	len = 0;
	if (!pointer)
		return (ft_putstr("(nil)"));
	address = (unsigned long)pointer;
	len += ft_putstr("0x");
	len += ft_printf_uint(address, 16);
	return (len);
}
