/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:34:07 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/10 21:36:45 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_putnbr(int n)
{
	long	nb2;
	char	c;
	int		count;

	nb2 = n;
	count = 0;
	if (n < 0)
	{
		nb2 = nb2 * (-1);
		count += ft_putchar("-");
	}
	if (nb2 / 10 != 0)
	{
		ft_putnbr(nb2 / 10);
	}
	c = nb2 % 10 + '0';
	count += ft_putchar(c);

	return (count);
}
