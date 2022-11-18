/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:39:51 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/18 19:00:12 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "libft/libft.h"

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
int		ft_printf(const char *string_input, ...);

//parser
int		parsing_options(va_list ap, char **str);

//print_*
int		print_conversions(t_data options, va_list ap, char **str);
int		print_c(int c, t_data options);
int		print_s(char *str, t_data options);
int		print_di(int number, t_data options);
int		print_u(unsigned int n, t_data options);
int		print_x(unsigned int n, t_data options, char c);
int		print_p(unsigned long address, t_data options);

//printers
int		ft_putchar(int c);
int		ft_putnchar(int c, int n);
int		ft_putnstr(char *str, int n);
void	ft_putnbr(int n, int *count);
void	ft_putuint(unsigned int n, int *count, t_data options);
void	ft_puthex(unsigned long n, int *count, char c, t_data options);

//helpers
int		prc_print(t_data options, int num_len);
int		wdt_print(t_data options, int longer, char c);
int		sign_print(t_data options, int number);
int		prefix_print(t_data options, char c, unsigned int n);
int		digit_number_check(int n);
int		get_longer(int prc, int num_len);
void	get_sign(int number, t_data *options);

#endif