/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:44 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 12:28:03 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	ft_radix(t_stack *a, t_stack *b)
// {
//     (void)a;
//     (void)b;
// }

// max_pos max position to shift
// >> shifts its binary bits to the right

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
