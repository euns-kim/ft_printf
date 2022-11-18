/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:08:09 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/20 20:43:55 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;
	size_t	i;

	if (n == 0)
		return (dst);
	if (dst == 0 && src == 0)
		return (0);
	cdst = (char *) dst;
	csrc = (char *) src;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
