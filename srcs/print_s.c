/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:09:42 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/14 20:20:35 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For printing string :

// Space, #, + will be ignored. Undefined behavior not handled for those.

// Only the chracter(s) of the size of the precision given will be printed.
// %.s will print out an empty string (""), as '.' is treated as '.0'.

// Even when the width given is smaller than the length of the string, the string will be printed as normal.
// When the width is bigger than the string, there will be (width - (precision or strlen)) of blank(s) printed.

// Flag 0 leads to undefined behavior.
// There is a warning sign while compiling, but it fills up 0(s) to the blank(s) in the result.
// But when 0 and - come together, 0 will be ignored. (No zerofill, left-justified)

// Flag - forces left justification.

// When the string given as an argument is a null pointer, the function prints out '(null)'.
// When the string given as an argument is an empty string, the function prints out "".
// When the function accidentally hits '\0' in the middle of the argument string,
// the printing of that argument will be terminated instantly.

#include "../ft_printf.h"

int	print_s(char *str, t_data *options)
{
	int	count;
	int	strlen;

	count = 0;
	if (!str)
		return (ft_putnstr("(null)", 6));
	strlen = (int) ft_strlen(str);
	if (options->dot == 1 && options->prc < strlen)
		strlen = options->prc;
	if (options->dash == 1)
	{
		count += ft_putnstr(str, strlen);
		count += ft_putnchar(' ', options->wdt - strlen);
	}
	else
	{
		if (options->wdt > strlen && options->zero == 0)
			count += ft_putnchar(' ', options->wdt - strlen);
		else if (options->wdt > strlen && options->zero == 1)
			count += ft_putnchar('0', options->wdt - strlen);
		count += ft_putnstr(str, strlen);
	}
	return (count);
}
