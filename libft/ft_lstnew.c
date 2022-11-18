/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:08:24 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/28 22:28:54 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = NULL;
	new = (t_list *) malloc (sizeof(t_list));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}
