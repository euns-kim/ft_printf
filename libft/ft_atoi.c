/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:12:17 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/28 17:28:13 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	sum;
	int			sign;

	sum = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		if (sum < 0 && sign == -1)
			return (0);
		else if (sum < 0 && sign == 1)
			return (-1);
		str++;
	}
	return ((int) sum * sign);
}
