/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:42:37 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/10 21:38:54 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For printing char ('%' included) :

// Precision, space, #, + will be ignored. Undefined behavior not handled.

// When width is bigger than 1, blank(s) will be printed out.
// Flag - forces left alligning.

// Flag 0 leads to undefined behavior.
// There is a warning sign while compiling, but it fills up 0(s) to the blank(s) in the result.
// But when 0 and - come together, 0 will be ignored. (No zerofill, left-justified)

// Test cases:
// printf("[%%]\n");					[%]					
// printf("[%5%]\n");					[    %]
// printf("[%-5%]\n");					[%    ]
// printf("[%05%]\n");					[0000%]
// printf("[%-05%]\n");					[%    ]

// Return value:
// If the width is bigger than 0, the width will be the number of characters that will be printed out.
// If the width is 0, the count and the output will be ft_putchar(c).

#include "../ft_printf.h"

int	print_c(int c, t_data *options)
{
	int	count;

	count = 0;
	if (options.dash == 1)
	{
		count += ft_putchar(c);
		count += ft_putnchar(' ', options.wdt - 1);
	}	
	else
	{
		if (options.wdt > 1 && options.zero == 0)
			count += ft_putnchar(' ', options.wdt - 1);
		else if (options.wdt > 1 && options.zero == 1)
			count += ft_putnchar('0', options.wdt - 1);
		count += ft_putchar(c);
	}
	return (count);
}
