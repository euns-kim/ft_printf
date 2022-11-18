/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:18:00 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/29 16:40:24 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 1;
	if (lst == 0)
		return (0);
	while (lst->next != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
