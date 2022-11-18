/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:31:44 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/21 22:06:25 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	p = malloc(count * size);
	if (p == 0)
		return (p);
	ft_memset(p, 0, count * size);
	return (p);
}
