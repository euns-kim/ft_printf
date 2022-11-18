/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:31:39 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/07 16:03:43 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*p;
	size_t	size;

	size = ft_strlen(s1) + 1;
	p = malloc(size);
	if (p == 0)
		return (0);
	ft_strlcpy((char *) p, s1, size);
	return ((char *) p);
}
