/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:44 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 13:59:14 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	max_pos_radix(int size)
{
	int		max_pos;
	int		max_index;

	max_index = size - 1;
	max_pos = 0;
	while ((max_index >> max_pos) != 0)
		max_pos++;
	return (max_pos);
}

static void	sort(t_stack *a, t_stack *b, int max, t_data *data)
{
	int		i;
	int		size;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (((a->top->index >> max) & 1) == 0)
			pb(a, b, data);
		else
			ra(a, data);
		i++;
	}
	while (b->size > 0)
		pa(a, b, data);
}

void	ft_radix(t_stack *a, t_stack *b, t_data *data)
{
	int		max_pos;
	int		max;

	max_pos = max_pos_radix(a->size);
	max = 0;
	while (max < max_pos)
	{
		sort(a, b, max, data);
		max++;
	}
}
