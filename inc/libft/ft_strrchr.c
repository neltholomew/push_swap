/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:31:10 by pcellar           #+#    #+#             */
/*   Updated: 2026/09/10 20:09:59 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	srclen;
	unsigned int	last_occurrence;

	i = 0;
	srclen = ft_strlen(s);
	last_occurrence = 0;
	while (i <= srclen)
	{
		if (s[i] == c)
			last_occurrence = i;
		i++;
	}
	if (s[last_occurrence] != c)
		return (NULL);
	return ((char *)&s[last_occurrence]);
}
