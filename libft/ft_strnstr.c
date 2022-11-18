/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:19:02 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/26 15:07:59 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	if (len == 0)
		return (0);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + j] != '\0' && needle[j] != '\0'
				&& i + j < len && haystack[i + j] == needle[j])
			{
				j++;
			}
			if (j == ft_strlen(needle))
				return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}
