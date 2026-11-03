/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:59:58 by pcellar           #+#    #+#             */
/*   Updated: 2026/09/16 13:57:47 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (ft_strlen(s1) == 0)
		end = 0;
	else
		end = ft_strlen(s1) - 1;
	start = 0;
	while (ft_strchr(set, s1[start]) != NULL && s1[start] != '\0')
	{
		start++;
	}
	while (ft_strrchr(set, s1[end]) != NULL && end > start && end != 0)
	{
		end--;
	}
	return (ft_substr(s1, start, end - start + 1));
}
