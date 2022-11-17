/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:37:07 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/17 18:15:40 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print(va_list ap, char *input);

int	ft_printf(const char *string_input, ...)
{
	int		count;
	char	*input;
	va_list	ap;

	input = (char *) string_input;
	va_start(ap, string_input);
	count = print(ap, input);
	va_end(ap);
	return (count);
}

static int	print(va_list ap, char *input)
{
	int	count;

	count = 0;
	while (*input)
	{
		if (*input != '%')
		{
			count += ft_putchar(*input);
			input++;
		}
		else
		{
			input++;
			count += parsing_options(ap, &input);
		}
	}
	return (count);
}
