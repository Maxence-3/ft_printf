/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-carv <mde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:59:28 by mde-carv          #+#    #+#             */
/*   Updated: 2025/11/17 17:59:57 by mde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int sign, int c)
{
	long	num;
	char	s;

	num = n;
	if (num < 0)
	{
		if (sign == 1)
		{
			write(1, "-", 1);
			c += 1;
		}
		num = -num;
	}
	if (num > 9)
		ft_putnbr(num / 10, sign, c);
	s = (num % 10) + '0';
	write(1, &s, 1);
	c += 1;
	return (c);
}

int	ft_print_hex(int n, char *base, int c)
{
	if (n >= 16)
		ft_print_hex(n / 16, base, c);
	ft_putchar(base[n % 16]);
	c += 1;
	return (c);
}

int	ft_print_ptr(void *ptr, int c)
{
	unsigned long	address;

	address = (unsigned long) ptr;
	c += ft_putstr("0x");
	c += ft_print_hex(address, "0123456789abcdef", c);
	return (c);
}
