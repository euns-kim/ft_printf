/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:07:54 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/17 19:29:07 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	parsing_flags(t_data *options, char **str);
static void	parsing_wdt_prc(int *num, char **str);

int	parsing_options(va_list ap, char **str)
{
	int		count;
	t_data	options;

	count = 0;
	ft_memset(&options, 0, sizeof(t_data));
	parsing_flags(&options, str);
	parsing_wdt_prc(&(options.wdt), str);
	if (**str == '.')
	{
		options.dot = 1;
		(*str)++;
		parsing_wdt_prc(&(options.prc), str);
	}
	if (ft_strchr("cspdiuxX%", **str) != 0)
	{
		count = print_conversions(options, ap, str);
	}
	return (count);
}

static void	parsing_flags(t_data *options, char **str)
{
	while (ft_strchr("-#0 +", **str) != 0)
	{
		if (**str == '-')
			options->dash = 1;
		else if (**str == '#')
			options->hash = 1;
		else if (**str == '0')
			options->zero = 1;
		else if (**str == ' ')
			options->space = 1;
		else if (**str == '+')
			options->plus = 1;
		(*str)++;
	}
}

static void	parsing_wdt_prc(int *num, char **str)
{
	while (**str >= '0' && **str <= '9')
	{
		*num = *num * 10 + (**str - '0');
		(*str)++;
	}
}
