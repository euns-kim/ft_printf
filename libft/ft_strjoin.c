/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:56:27 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/07 16:13:58 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == NULL)
		return (0);
	while (s1[i])
	{
		newstr[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		newstr[j++] = s2[i++];
	}
	newstr[j] = '\0';
	return (newstr);
}
