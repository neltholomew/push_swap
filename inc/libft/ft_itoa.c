/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:01:07 by pcellar           #+#    #+#             */
/*   Updated: 2026/10/19 12:48:31 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	len;
	long	nko;
	char	*ptr;

	nko = n;
	len = ft_intlen(nko);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	if (nko < 0)
	{
		nko *= -1;
		ptr[0] = '-';
	}
	ptr[len] = '\0';
	len--;
	if (nko == 0)
		ptr[len] = '0';
	while (nko > 0)
	{
		ptr[len--] = nko % 10 + '0';
		nko = nko / 10;
	}
	return (ptr);
}
