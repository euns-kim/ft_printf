/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:09:42 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/18 17:25:23 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For printing string :

// Space, #, + will be ignored. Undefined behavior not handled.

// Only the chracter(s) of the size of the precision given will be printed.
// %.s will print out an empty string (""), as '.' is treated as '.0'.

// Even when the width is smaller than the strlen,
// the whole string will be printed as normal.
// When the width is bigger than the strlen,
// there will be (width - (precision/strlen)) of blank(s).

// Flag 0 leads to undefined behavior.
// There is a warning sign while compiling,
// but it fills up 0(s) to the blank(s) in the result.
// When the - flag is on, 0 will be ignored. (No zerofill, left-justified)

// Flag - forces left justification.

// When the string given as an argument is a null pointer,
// the function prints out '(null)'.
// When the string given as an argument is an empty string,
// the function prints out "".
// When the function accidentally hits '\0' in the middle of the argument,
// the printing of that argument will be terminated instantly.

#include "../ft_printf.h"

static int	handle_null(char **str, int *status);
static void	printing_print_s(char *str, int strlen, t_data options, int *count);

int	print_s(char *str, t_data options)
{
	int	count;
	int	strlen;
	int	status;

	count = 0;
	if (!handle_null(&str, &status))
		return (-1);
	strlen = (int) ft_strlen(str);
	if (options.dot == 1 && options.prc < strlen)
		strlen = options.prc;
	printing_print_s(str, strlen, options, &count);
	if (status)
		free (str);
	return (count);
}

static int	handle_null(char **str, int *status)
{
	*status = 0;
	if (*str == NULL)
	{
		*str = ft_strdup("(null)");
		if (*str == NULL)
			return (0);
		*status = 1;
	}
	return (1);
}

static void	printing_print_s(char *str, int strlen, t_data options, int *count)
{
	int	padding;

	padding = options.wdt - strlen;
	if (options.dash == 1)
	{
		*count += ft_putnstr(str, strlen);
		*count += ft_putnchar(' ', padding);
	}
	else
	{
		if (options.zero == 0)
			*count += ft_putnchar(' ', padding);
		else if (options.zero == 1)
			*count += ft_putnchar('0', padding);
		*count += ft_putnstr(str, strlen);
	}
}
