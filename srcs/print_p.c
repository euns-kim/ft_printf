/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:20 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/17 17:02:06 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For printing %p:
// width, - are to be concerned.

// 1. left-justified
// 			(number)(blank)

// 2. right-justified
// 			(blank)(number)

#include "../ft_printf.h"

int	print_p(unsigned long address, t_data options)
{
	int	count;
	int	add_len;

	count = 0;
	add_len = hex_len_check(address);
	if (options.dash == 0)
		count += wdt_print(options, add_len + 2, ' ');
	count += prefix_print(options, 'x');
	ft_puthex(address, &count, 'x');
	if (options.dash == 1)
		count += wdt_print(options, add_len + 2, ' ');
	return (count);
}
