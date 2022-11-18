/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:30:25 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/28 17:47:42 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb2;
	char	c;

	nb2 = n;
	if (n < 0)
	{
		nb2 = nb2 * (-1);
		write(fd, "-", 1);
	}
	if (nb2 / 10 != 0)
	{
		ft_putnbr_fd(nb2 / 10, fd);
	}
	c = nb2 % 10 + '0';
	write(fd, &c, 1);
}
