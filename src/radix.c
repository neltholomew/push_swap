/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:44 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/12 16:17:19 by tarebros         ###   ########.fr       */
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

static void	sort(t_stack *a, t_stack *b, int max)
{
	int		i;
	int		size;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (((a->top->index >> max) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (b->size > 0)
		pa(a, b);
}

void	ft_radix(t_stack *a, t_stack *b)
{
	int		max_pos;
	int		max;
	// int		i;
	// t_node	*curr;

	max_pos = max_pos_radix(a->size);
	max = 0;
	while (max < max_pos)
	{
		sort(a, b, max);
		max++;
	}
	// i = 0;
	// curr = a->top;
	// while (i < a->size)
	// {
	// 	ft_printf("%d\n", curr->value);
	// 	curr = curr->next;
	// 	i++;
	// }
}
