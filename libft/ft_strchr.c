/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:04:51 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/18 19:28:11 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
