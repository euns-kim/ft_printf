/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:33:04 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/07 13:31:45 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_next;
	void	*new_content;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	new_head = NULL;
	while (lst)
	{	
		new_content = f(lst->content);
		new_next = ft_lstnew(new_content);
		if (new_next == 0)
		{
			del(new_content);
			if (new_head)
				ft_lstclear(&new_head, del);
			return (0);
		}
		ft_lstadd_back(&new_head, new_next);
		lst = lst->next;
	}
	return (new_head);
}
