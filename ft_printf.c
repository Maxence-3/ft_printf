/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-carv <mde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:57:42 by mde-carv          #+#    #+#             */
/*   Updated: 2025/11/17 18:01:21 by mde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	function_call(char *s, int i, va_list args)
{
	int	c;

	c = 0;
	if (s[i] == 'c')
		c += ft_putchar(va_arg(args, int));
	if (s[i] == 's')
		c += ft_putstr(va_arg(args, char *));
	if (s[i] == 'p')
		c += ft_print_ptr(va_arg(args, void *), c);
	if (s[i] == 'd')
		c += ft_putnbr(va_arg(args, int), 1, c);
	if (s[i] == 'i')
		c += ft_putnbr(va_arg(args, int), 1, c);
	if (s[i] == 'u')
		c += ft_putnbr(va_arg(args, int), 0, c);
	if (s[i] == 'x')
		c += ft_print_hex(va_arg(args, int), "0123456789abcdef", c);
	if (s[i] == 'X')
		c += ft_print_hex(va_arg(args, int), "0123456789ABCDEF", c);
	if (s[i] == '%')
	{
		write(1, "%", 1);
		c += 1;
	}
	return (c);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		c;

	va_start(args, s);
	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			c += function_call((char *)s, i, args);
		}
		else
			c += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (c);
}

/* int	main(void)
{
	ft_printf("%c", 'c');
	ft_printf("%c", '\n');
	ft_printf("%s", "coucou");
	ft_printf("%c", '\n');
	ft_printf("%p", "coucou");
	ft_printf("%c", '\n');
	ft_printf("%d", -1312);
	ft_printf("%c", '\n');
	ft_printf("%i", -1312);
	ft_printf("%c", '\n');
	ft_printf("%u", -1312);
	ft_printf("%c", '\n');
	ft_printf("%x", 13121312);
	ft_printf("%c", '\n');
	ft_printf("%X", 13121312);
	ft_printf("%c", '\n');
	ft_printf("%%");
	ft_printf("%c", '\n');
	ft_printf("Coucou %s %c%c", "tout le monde", '!', '\n');
	ft_printf("%c", '\n');
	// ft_printf("%s\n", NULL);
	return (0);
} */
