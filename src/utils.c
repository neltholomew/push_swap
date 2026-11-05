/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:30:00 by tatiana           #+#    #+#             */
/*   Updated: 2026/11/05 14:48:58 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_isdup(int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

// ft_bench();
// [bench] disorder: 40.00%
// [bench] strategy: Adaptive / O(n log n)
// [bench]	total_ops: 13
// [bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
// [bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
