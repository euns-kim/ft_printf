/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:31:54 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/28 16:16:56 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*newstring;

	len = ft_strlen(s);
	i = 0;
	newstring = malloc (sizeof(char) * (len + 1));
	if (newstring == 0)
		return (0);
	while (i < len)
	{
		*(newstring + i) = f (i, *(s + i));
		i++;
	}
	newstring[len] = 0;
	return (newstring);
}
