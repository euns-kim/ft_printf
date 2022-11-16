/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di_helper_sign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:58:52 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/15 19:18:57 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	sign_print(t_data options, int number)
{
	int	count;

	count = 0;
	if (number >= 0 && options.plus == 1)
	{
		count += ft_putchar("+");
		return (count);
	}
	else if (number >= 0 && options.space == 1)
		count += ft_putchar(" ");
	else if (number < 0)
		count += ft_putchar("-");
	return (count);
}

void	get_sign(int number, t_data *options)
{
	if ((number >= 0 && options->plus == 1)
		|| (number >= 0 && options->space == 1)
		|| number < 0)
		options->sign = 1;
}
