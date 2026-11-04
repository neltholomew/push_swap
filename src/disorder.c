/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:35 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/04 16:49:23 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

float	compute_disorder(char *stack_a)
{
	float	mistakes = 0;
	float	total_pairs = 0;
	int		i;
	int		j;

	i = 0;
	while (i < (ft_strlen(stack_a) - 1))
	{
		j = i + 1;
		while(j < (int stack_a - 1))
		{
			total_pairs += 1;
			if stack_a[i] > stack_a[j]
				mistakes += 1;
		}
	}
	return (mistakes / total_pairs);
}
