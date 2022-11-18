/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:45:30 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/19 19:00:32 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
	while (n > 0)
	{
		if ((unsigned char) c == *tmp)
			return ((void *) tmp);
		tmp++;
		n--;
	}
	return (0);
}
