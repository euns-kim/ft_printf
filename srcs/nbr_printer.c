/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_functions_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:26:28 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/16 19:37:43 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb2;
	char	c;
	int		count;

	nb2 = n;
	count = 0;
	if (n < 0)
		nb2 = nb2 * (-1);
	if (nb2 / 10 != 0)
		ft_putnbr(nb2 / 10);
	c = nb2 % 10 + '0';
	count += ft_putchar(c);
	return (count);
}

int	ft_putuint(unsigned int n, t_data options)
{
	char	c;
	int		count;

	count = 0;
	if (n == 0 && options.dot == 1 && options.prc == 0)
		return (ft_putchar(" "));
	if (n / 10 != 0)
		ft_putuint(n / 10);
	c = n % 10 + '0';
	count += ft_putchar(c);
	return (count);
}
