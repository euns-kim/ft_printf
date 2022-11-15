/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:37:07 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/10 21:38:24 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print(va_list ap, const char *input);

int	ft_printf(const char *input, ...)
{
	int 	count;
	va_list ap;

	va_start(ap, input);
	count = print(ap, input);
	va_end(ap);

	return (count);
}

int	print(va_list ap, const char *input)
{
	int		count;

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
