/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:11:17 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/17 19:25:11 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_conversions(t_data options, va_list ap, char **str)
{
	int	count;

	count = 0;
	if (**str == 'c')
		count += print_c(va_arg(ap, int), options);
	else if (**str == 's')
		count += print_s(va_arg(ap, char *), options);
	else if (**str == 'p')
		count += print_p(va_arg(ap, unsigned long), options);
	else if (**str == 'd' || **str == 'i')
		count += print_di(va_arg(ap, int), options);
	else if (**str == 'u')
		count += print_u(va_arg(ap, unsigned int), options);
	else if (**str == 'x' || **str == 'X')
		count += print_x(va_arg(ap, unsigned int), options, **str);
	else if (**str == '%')
		count += print_c('%', options);
	(*str)++;
	return (count);
}
