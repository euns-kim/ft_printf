/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:27:31 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/07 18:28:57 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_strings(char const *s, char c);
static char		*generate_substrings(size_t *substr_len, char const *s, char c);
static void		*free_strings(char **ptr);

char	**ft_split(char const *s, char c)
{
	size_t	substr_len;
	char	**newarray;
	char	**newarray_cpy;

	newarray = (char **) malloc (sizeof(char *) * (count_strings(s, c) + 1));
	if (newarray == 0)
		return (0);
	newarray_cpy = newarray;
	while (*s)
	{
		if (*s != c)
		{
			*newarray = generate_substrings(&substr_len, s, c);
			if (*newarray == 0)
			{
				free_strings(newarray_cpy);
				return (0);
			}
			s = s + substr_len - 1;
			newarray++;
		}
		s++;
	}
	*newarray = 0;
	return (newarray_cpy);
}

static int	count_strings(char const *s, char c)
{
	size_t	i;
	size_t	len;
	int		string_count;

	i = 0;
	string_count = 0;
	if (s == 0 || s[0] == '\0')
		return (0);
	len = ft_strlen(s);
	if (s[0] != '\0' && s[0] != c)
		string_count = 1;
	while (i < len - 1)
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				string_count++;
		}
		i++;
	}
	return (string_count);
}

static char	*generate_substrings(size_t *substr_len, char const *s, char c)
{
	char	*result;

	*substr_len = 0;
	while (*(s + *substr_len) != '\0' && *(s + *substr_len) != c)
		*substr_len += 1;
	result = ft_substr(s, 0, *substr_len);
	return (result);
}

static void	*free_strings(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != 0)
	{
		free (ptr[i]);
		i++;
	}
	free (ptr);
	return (0);
}
