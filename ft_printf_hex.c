/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-carv <mde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:20:38 by mde-carv          #+#    #+#             */
/*   Updated: 2025/11/18 13:21:24 by mde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char *base)
{
	int	c;

	c = 0;
	if (n >= 16)
		c += ft_print_hex(n / 16, base);
	c += ft_putchar(base[n % 16]);
	return (c);
}

int	ft_print_hex_long(unsigned long n, char *base)
{
	int	c;

	c = 0;
	if (n >= 16)
		c += ft_print_hex_long(n / 16, base);
	c += ft_putchar(base[n % 16]);
	return (c);
}

int	ft_print_ptr(void *ptr)
{
	int				c;
	unsigned long	address;

	c = 0;
	if (!ptr)
	{
		c += ft_putstr("(nil)");
		return (c);
	}
	address = (unsigned long) ptr;
	c += ft_putstr("0x");
	c += ft_print_hex_long(address, "0123456789abcdef");
	return (c);
}
