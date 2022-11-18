/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prc_wdt_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:57:00 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/18 16:18:01 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	prc_print(t_data options, int num_len)
{
	int	count;
	int	padding;

	count = 0;
	padding = options.prc - num_len;
	count += ft_putnchar('0', padding);
	return (count);
}

int	wdt_print(t_data options, int longer, char c)
{
	int	count;
	int	padding;

	count = 0;
	padding = options.wdt - longer;
	count += ft_putnchar(c, padding);
	return (count);
}

int	digit_number_check(int n)
{
	int	digit_number;

	digit_number = 0;
	if (n == 0)
		digit_number = 1;
	while (n)
	{
		n = n / 10;
		digit_number++;
	}
	return (digit_number);
}

int	get_longer(int prc, int num_len)
{
	int	longer;

	longer = prc;
	if (prc < num_len)
		longer = num_len;
	return (longer);
}
