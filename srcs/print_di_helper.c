/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:57:00 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/15 19:01:42 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	prc_print(t_data options, int number)
{
	int	count;
	int	digit_number;
	int	padding;

	count = 0;
	digit_number = digit_number_check(number);
	padding = options.prc - digit_number;
	if (padding > 0)
		count += ft_putnchar("0", padding);
	if (!(number == 0 && options.dot == 1 && options.prc == 0))
		count += ft_putnbr(number);
	return (count);
}

int	wdt_print(t_data options, int number, char c)
{
	int	count;
	int	digit_number;
	int	longer;
	int	padding;

	count = 0;
	digit_number = digit_number_check(number);
	longer = get_longer(options.prc, digit_number);
	get_sign(number, &options);
	padding = options.wdt - longer - options.sign;
	if (padding > 0)
		count += ft_putnchar(c, padding);
	return (count);
}

int	digit_number_check(int n)
{
	int	digit_number;

	digit_number = 0;
	while (n)
	{
		n = n / 10;
		digit_number++;
	}
	return (digit_number);
}

int	get_longer(int prc, int digit_number)
{
	int	longer;

	longer = prc;
	if (prc < digit_number)
		longer = digit_number;
	return (longer);
}
