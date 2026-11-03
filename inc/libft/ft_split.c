/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:00:41 by pcellar           #+#    #+#             */
/*   Updated: 2026/09/16 13:22:26 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	free_result(char **result, size_t i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

static char	**fill_words(char **result, char const *s, char c)
{
	size_t	i;
	size_t	start;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		start = 0;
		while (s[start] && s[start] != c)
			start++;
		if (start > 0)
		{
			result[i] = ft_substr(s, 0, start);
			if (!result[i])
			{
				free_result(result, i);
				return (NULL);
			}
			i++;
			s += start;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;

	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	return (fill_words(result, s, c));
}
