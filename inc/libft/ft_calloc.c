/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:52:55 by pcellar           #+#    #+#             */
/*   Updated: 2026/10/19 12:46:33 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if ((size_t)-1 / nmemb < size)
		return (NULL);
	ptr = (void *)malloc (size * nmemb);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return ((void *)ptr);
}
