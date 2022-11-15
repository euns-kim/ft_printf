/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_functions_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:34:07 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/15 18:30:23 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnchar(int c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write (1, &c, 1);
		i++;
	}
	return (n);
}

int	ft_putnstr(char *str, int n)
{
	write (1, str, n);
	return (n);
}
