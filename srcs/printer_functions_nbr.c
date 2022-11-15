/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_functions_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:26:28 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/15 18:27:48 by eunskim          ###   ########.fr       */
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
