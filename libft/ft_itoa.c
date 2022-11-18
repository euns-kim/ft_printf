/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:25:55 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/07 12:33:25 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		digit_number_check(int n);

char	*ft_itoa(int n)
{
	int			digit_number;
	long long	number;
	char		*result;

	number = n;
	digit_number = digit_number_check(n);
	result = malloc (sizeof(char) * (digit_number + 1));
	if (result == 0)
		return (0);
	*(result + digit_number) = 0;
	*(result) = '-';
	if (n == 0)
		*(result) = '0';
	else if (n < 0)
		number *= (-1);
	while (number != 0)
	{
		*(result + digit_number - 1) = (number % 10) + '0';
		number = number / 10;
		digit_number--;
	}
	return (result);
}

static int	digit_number_check(int n)
{
	int	digit_number;

	digit_number = 0;
	if (n <= 0)
		digit_number = 1;
	while (n)
	{
		n = n / 10;
		digit_number++;
	}
	return (digit_number);
}
