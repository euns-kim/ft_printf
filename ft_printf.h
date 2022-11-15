/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:39:51 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/14 18:42:58 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

# include "../libft/libft.h"

typedef struct s_data
{
	int	type;
	int	plus;
	int	dash;
	int	zero;
	int	space;
	int	hash;
	int	wdt;
	int	dot;
	int	prc;
	int	sign;
}	t_data;

int	ft_printf(const char *input, ...);
int	parsing_options(va_list ap, char **str);
int	ft_putchar(int c);
int	ft_putnchar(int c, int n);
// int ft_putstr(char *str)
int	ft_putnstr(char *str, int n);
// int	ft_putnbr(int n);
int	print_c(int c, t_data *options);
int	print_s(char *str, t_data *options);

#endif