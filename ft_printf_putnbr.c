/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-carv <mde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:19:35 by mde-carv          #+#    #+#             */
/*   Updated: 2025/11/18 13:09:33 by mde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	num;
	char	s;
	int		c;

	num = n;
	c = 0;
	if (num < 0)
	{
		c += ft_putchar('-');
		num = -num;
	}
	if (num > 9)
		c += ft_putnbr(num / 10);
	s = (num % 10) + '0';
	c += ft_putchar(s);
	return (c);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	long	num;
	char	s;
	int		c;

	num = n;
	c = 0;
	if (num > 9)
		c += ft_putnbr_unsigned(num / 10);
	s = (num % 10) + '0';
	c += ft_putchar(s);
	return (c);
}
