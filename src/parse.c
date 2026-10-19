/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:50:01 by pcellar           #+#    #+#             */
/*   Updated: 2026/10/19 15:21:18 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}


int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*word_split(char const *s, char c)
{
	char	*word;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

void	free_words(char **words, int j)
{
	while (j > 0)
		free(words[--j]);
	free(words);
}

int	fill_words(char **words, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		words[j] = word_split(&s[i], c);
		if (!words[j])
		{
			free_words(words, j);
			return (0);
		}
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	words[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!words)
		return (NULL);
	if (!fill_words(words, s, c))
		return (NULL);
	return (words);
}

int is_valid(char *arr)
{
	int	i;
	int status;

	i = 0;
	while (arr[i])
	{
		status = ft_isdigit(arr[i]);
		i++;
	}
	return (status);
}
int	ft_isdup(char *arr)
{
	int i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while ()
		{
			if (i == j)
				j++;
			if (arr[i] == arr[j])
				return (ERROR);
			j++;
		}
		i++;
	}

}

void	ft_parse(char *argv)
{
	char **arr;
	int status;

	arr = ft_split(argv, ' ');
	status = isvalid(*arr);
	//ft_atoi()
	status = ft_isdup(*arr);
}

// int main(void)
// {
// 	ft_parse("1");
// }
