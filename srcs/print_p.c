/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:20 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/18 17:55:45 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For printing %p:
// width, - are to be concerned.

// 1. left-justified
// 			(number)(blank)

// 2. right-justified
// 			(blank)(number)

#include "../ft_printf.h"

static int	add_len_check(unsigned long n);

int	print_p(unsigned long address, t_data options)
{
	int	count;
	int	add_len;

	count = 0;
	add_len = add_len_check(address);
	if (options.dash == 0)
		count += wdt_print(options, add_len + 2, ' ');
	count += ft_putnstr("0x", 2);
	ft_puthex(address, &count, 'x', options);
	if (options.dash == 1)
		count += wdt_print(options, add_len + 2, ' ');
	return (count);
}

static int	add_len_check(unsigned long n)
{
	int	add_len;

	add_len = 0;
	if (n == 0)
		add_len = 1;
	while (n)
	{
		n = n / 16;
		add_len++;
	}
	return (add_len);
}
