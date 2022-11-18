/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:31:55 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/19 17:49:17 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*to;
	char	*from;

	to = (char *) dst;
	from = (char *) src;
	if (len == 0 || dst == src)
		return (dst);
	if (to > from && to - from < (int) len)
	{
		while (len > 0)
		{
			to[len - 1] = from[len - 1];
			len--;
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
