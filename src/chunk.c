/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:32 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 12:27:47 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// chunk size is sqrt rounded up - 10 for 100 numbers, 23 for 500

static int	ft_get_range(int size)
{
	int	root;

	root = 1;
	while (root * root < size)
		root++;
	return (root);
}

// push everything to b, index i is how many were pushed
// small ones (<= i) go to the bottom of b

static void	ft_push_chunks(t_stack *a, t_stack *b, int range, t_data *data)
{
	int	i;

	i = 0;
	while (a->size > 0)
	{
		if (a->top->index <= i)
		{
			pb(a, b, data);
			i++;
			// larger numbers stay on top
			if (a->size > 0 && a->top->index > i + range)
				rr(a, b, data);
			else if (b->size > 1)
				rb(b, data);
		}
		// larger numbers stay on top
		else if (a->top->index <= i + range)
		{
			pb(a, b, data);
			i++;
		}
		else
			ra(a, data);
	}
}

// position of the biggest index in b, counted from the top
// max pos assumes: b->size > 0
//	 				b->top != NULL

static int	ft_max_pos(t_stack *b)
{
	t_node	*node;
	int		max_pos;
	int		max;
	int		i;

	node = b->top;
	max = node->index;
	max_pos = 0;
	i = 0;
	while (i < b->size)
	{
		if (node->index > max)
		{
			max = node->index;
			max_pos = i;
		}
		node = node->next;
		i++;
	}
	return (max_pos);
}

// get the biggest number of b to the top the shorter way, then pa

static void	ft_push_back(t_stack *a, t_stack *b, t_data *data)
{
	int	pos;

	while (b->size > 0)
	{
		pos = ft_max_pos(b);
		// when biggest number is in the first half
		if (pos <= b->size / 2)
		{
			while (pos-- > 0)
				rb(b, data);
		}
		else
		{
			while (pos < b->size)
			{
				rrb(b, data);
				pos++;
			}
		}
		pa(a, b, data);
	}
}

void	ft_chunk(t_stack *a, t_stack *b, t_data *data)
{
	ft_push_chunks(a, b, ft_get_range(a->size), data);
	ft_push_back(a, b, data);
}
