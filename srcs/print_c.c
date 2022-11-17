/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:42:37 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/17 16:54:08 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For printing char ('%' included) :

// Precision, space, #, + will be ignored. Undefined behavior not handled.

// When width is bigger than 1, blank(s) will be printed out.
// Flag - forces left justification.

// Flag 0 leads to undefined behavior.
// There is a warning sign while compiling,
// but it fills up 0(s) to the blank(s) in the result.
// When the - flag is on, 0 will be ignored. (No zerofill, left-justified)

// Test cases:
// printf("[%%]\n");					[%]					
// printf("[%5%]\n");					[    %]
// printf("[%-5%]\n");					[%    ]
// printf("[%05%]\n");					[0000%]
// printf("[%-05%]\n");					[%    ]

#include "../ft_printf.h"

int	print_c(int c, t_data options)
{
	int	count;
	int	padding;

	count = 0;
	padding = options.wdt - 1;
	if (options.dash == 1)
	{
		count += ft_putchar(c);
		count += ft_putnchar(' ', padding);
	}
	else
	{
		if (options.zero == 0)
			count += ft_putnchar(' ', padding);
		else if (options.zero == 1)
			count += ft_putnchar('0', padding);
		count += ft_putchar(c);
	}
	return (count);
}
