/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:26:28 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/17 16:06:12 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long	nb2;
	char	c;

	nb2 = n;
	if (n < 0)
		nb2 = nb2 * (-1);
	if (nb2 / 10 != 0)
		ft_putnbr(nb2 / 10, *count);
	c = nb2 % 10 + '0';
	*count += ft_putchar(c);
}

void	ft_putuint(unsigned int n, int *count, t_data options)
{
	char	c;

	if (n == 0 && options.dot == 1 && options.prc == 0)
		return (ft_putchar(" "));
	if (n / 10 != 0)
		ft_putuint(n / 10, *count, options);
	c = n % 10 + '0';
	*count += ft_putchar(c);
}

void	ft_puthex(unsigned long n, int *count, char c)
{
	char	c;

	if (n / 16 != 0)
		ft_puthex(n / 16, *count, c);
	if (n % 16 > 9 && c == 'X')
		c = n % 16 - 10 + 'A';
	else if (n % 16 > 9 && c == 'x')
		c = n % 16 - 10 + 'a';
	else if (n % 16 < 10)
		c = n % 16 + '0';
	*count += ft_putchar(c);
}