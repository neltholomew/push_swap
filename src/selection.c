/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:37 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/12 15:18:54 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_min_pos(t_stack *a)
{
	t_node	*node;
	int		min_pos;
	int		min;
	int		i;

	node = a->top;
	min = node->index;
	min_pos = 0;
	i = 0;
	while (i < a->size)
	{
		if (node->index < min)
		{
			min = node->index;
			min_pos = i;
		}
		node = node->next;
		i++;
	}
	return (min_pos);
}

static void	ft_sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->prev->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	ft_bring_min_to_top(t_stack *a)
{
	int	pos;

	pos = ft_min_pos(a);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos < a->size)
		{
			rra(a);
			pos++;
		}
	}
}

void	ft_selection(t_stack *a, t_stack *b)
{
	t_node	*curr;
	int		i;

	if (a->size <= 1)
	return ;
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
		sa(a);
		return ;
	}
	while (a->size > 3)
	{
		ft_bring_min_to_top(a);
		pb(a, b);
	}
	ft_sort_three(a);
	while (b->size > 0)
    	pa(a, b);
	curr = a->top;
	i = 0;
	while (i < a->size)
	{
		ft_printf("%d\n", curr->value);
		curr = curr->next;
		i++;
	}
}
