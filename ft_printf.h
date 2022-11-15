/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:39:51 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/15 19:32:43 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_data
{
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

//main + main printer
int	ft_printf(const char *input, ...);

//parser
int	parsing_options(va_list ap, char **str);

//print_*
int	print_conversions(t_data options, va_list ap, char **str);
int	print_c(int c, t_data options);
int	print_s(char *str, t_data options);
int	print_di(int number, t_data options);

//printers
int	ft_putchar(int c);
int	ft_putnchar(int c, int n);
int	ft_putnstr(char *str, int n);
int	ft_putnbr(int n);

//helpers
int		prc_print(t_data options, int number);
int		wdt_print(t_data options, int number, char c);
int		sign_print(t_data options, int number);
int		digit_number_check(int n);
int		get_longer(int prc, int digit_number);
void	get_sign(int number, t_data *options);

#endif