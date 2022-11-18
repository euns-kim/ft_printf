/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:30:35 by eunskim           #+#    #+#             */
/*   Updated: 2022/10/29 22:35:50 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set);
static size_t	ft_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstring;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	i = 0;
	newstring = malloc(sizeof(char) * (end - start + 1));
	if (newstring == 0)
		return (0);
	while (i < end - start)
	{
		newstring[i] = s1[start + i];
		i++;
	}
	newstring[end - start] = '\0';
	return (newstring);
}

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - 1 - i]) == 0)
			break ;
		i++;
	}
	return (len - i);
}
