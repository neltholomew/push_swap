/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:09:35 by pcellar           #+#    #+#             */
/*   Updated: 2026/09/16 13:52:54 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	i = ft_strlen(dest);
	j = 0;
	srclen = ft_strlen(src);
	dstlen = i;
	if (dstsize == 0)
		return (dstsize + srclen);
	else if (dstlen >= dstsize)
		return (dstsize + srclen);
	else
	{
		while (src[j] != '\0' && i != dstsize -1)
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
	}
	return (dstlen + srclen);
}
