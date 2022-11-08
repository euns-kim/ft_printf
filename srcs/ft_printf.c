/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:37:07 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/08 20:54:26 by eunskim          ###   ########.fr       */
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

int	parsing_options(va_list ap, char **str)
{
	int		count;
	t_data	options;

	count = 0;
	ft_memset(&options, 0, sizeof(t_data));
	parsing_flags(&options, &str);
	parsing_wdt_prc(&(options->wdt), &str);
	if (*str = '.')
	{
		options->dot = 1;
		parsing_wdt_prc(&(options->prc), &str);
	}
	if (ft_strchr("cspdiuxX%", *str) != 0)
	{
		count = print_conversions(&options, ap);
	}
	return (count);
}

void	parsing_flags(t_data *options, char **str)
{
	while (ft_strchr("-#0 +", *str) != 0)
	{
		if (*str == '-')
			options->dash = 1;
		else if (*str == '#')
			options->hash = 1;
		else if (*str == '0')
			options->zero = 1;
		else if (*str == ' ')
			options->space = 1;
		else if (*str == '+')
			options->plus = 1;
		str++;
	}
}

void	parsing_wdt_prc(int *num, char **str)
{
	while (*str >= '0' && *str <= '9')
	{
		*num = *num * 10 + (*str - '0');
		str++;
	}
}

int	print_conversions(t_data *options, va_list ap, char **str)
{
	if (*str == 'c')
		count += print_c(va_arg(ap, int), options);
	else if (*str == 's')
		count += print_s(va_arg(ap, char *), options);
	else if (*str == 'p')
		count += print_p(va_arg(ap, void *), options);
	else if (*str == 'd' || *str == 'i')
		count += print_di(va_arg(ap, int), options);
	else if (*str == 'u')
		count += print_u(va_arg(ap, unsigned int), options);
	else if (*str == 'x' || 'X')
		count += print_xX(va_arg(ap, unsigned int), options);
	else
		count += print_c('%', options);
	return (count);
}
