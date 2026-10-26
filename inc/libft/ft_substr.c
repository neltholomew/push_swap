/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:58:01 by pcellar           #+#    #+#             */
/*   Updated: 2026/10/19 12:58:30 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (start <= ft_strlen(s) && j < start + len && s[j] != '\0')
	{
		ptr[i] = s[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
