/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:37:07 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/08 19:15:16 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char	*str;
	int		count;

	str = (char *) input;
	count = 0;
	while (str)
	{
		if (str != '%')
		{
			count += ft_putchar(*str);
			str++;
		}
		else
			str++;
			count += parsing_options(ap, &str);
	}
	return (count);
}

int	parsing_options(va_list ap, char **str)
{
	int		count;
	t_data	*options;

	count = 0;
	options = malloc (sizeof(t_data));
	if (options == 0)
		return (0);
	if (*str == '%')
	{
		count += ft_putchar('%');
		return (count);
	}
	ft_memset(options, 0, sizeof(t_data));
	parsing_flags(options, &str);
	parsing_wdt(options, &str);
	parsing_dot_prc(options, &str);
	while (ft_strchr("cspdiuxX", *str) != 0)
	{
		count = print_conversions(options, ap);
	}
	return (count);
}
	// FOR PRINTING % EXCEPTIONAL CONVERTING CASES NOT REGARDED

char	*parsing_flags(t_data *options, char **str)
{
	while (ft_strchr("-#0 +", *str) != 0)
	{
		if (*str == '-')
			options.dash = 1;
		else if (*str == '#')
			options.hash = 1;
		else if (*str == '0')
			options.zero = 1;
		else if (*str == ' ')
			options.space = 1;
		else if (*str == '+')
			options.plus = 1;
		str++;
	}
	return (&str);
}

char	*parsing_wdt(t_data *options, char **str)
{
	while (*str >= '0' && *str <= '9')
	{
		options.wdt = options.wdt * 10 + (*str - '0');
		str++;
	}
	return (&str);
}

char	*parsing_dot_prc(t_data *options, char **str)
{
	if (*str == '.')
	{
		options.dot = 1;
		str++;
		while (*str >= '0' && *str <= '9')
		{
			options.prc = options.prc * 10 + (*str - '0');
			str++;
		}
	}
	return (&str);
}

int	print_conversions(t_data *options, va_list ap, char **str)
{
	if (*str == 'c')
		count += print_c(va_arg(), options);
	else if (*str == 's')
		count += print_s(va_arg(), options);
	else if (*str == 'p')
		count += print_p(va_arg(), options);
	else if (*str == 'd' || *str == 'i')
		count += print_di(va_arg(), options);
	else if (*str == 'u')
		count += print_u(va_arg(), options);
	else if (*str == 'x' || 'X')
		count += print_xX(va_arg(), options);
	return (count);
}