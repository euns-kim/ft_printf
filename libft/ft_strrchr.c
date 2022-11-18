/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:28:48 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/18 19:44:47 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s + ft_strlen(s) - 1;
	if ((char) c == '\0')
		return ((char *) p + 1);
	while (p >= s)
	{
		if ((char) c == *p)
			return ((char *) p);
		p--;
	}
	return (0);
}
