/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:40:58 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/17 13:49:57 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len != 0)
	{
		*p++ = (unsigned char) c;
		len--;
	}
	return (b);
}

char	*ft_strchr(const char *s, int c)
{
	if ((char) c == '\0')
		return ((char *)s + ft_strlen(s));
	else
	{
		while (*s)
		{
			if ((char) c == *s)
				return ((char *)s);
			s++;
		}
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	strlen;

	strlen = 0;
	while (s[strlen] != '\0')
		strlen++;
	return (strlen);
}
