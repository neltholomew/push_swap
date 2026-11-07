/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatiana <tatiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:35 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/06 18:37:36 by tatiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_dispatcher(t_status *st, t_stack *a, t_stack *b)
{
	if (st->disorder == 0)
		return ;
	if (st->flag == SIMPLE || (st->flag == ADAPTIVE && (st->size <= 5
				|| st->disorder < 0.2)))
		ft_insertion(a, b);
	else if (st->flag == MEDIUM || (st->flag == ADAPTIVE && st->disorder < 0.5))
		ft_chunk(a, b);
	else
		ft_radix(a, b);
}

float	compute_disorder(int *values, int size)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	if (size < 2)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (values[i] > values[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float)mistakes / total_pairs);
}
