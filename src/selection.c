/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:37 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 13:23:51 by pcellar          ###   ########.fr       */
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

static void	ft_sort_three(t_stack *a, t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->prev->index;
	if (first > second && second < third && first < third)
		sa(a, data);
	else if (first > second && second > third)
	{
		sa(a, data);
		rra(a, data);
	}
	else if (first > second && second < third && first > third)
		ra(a, data);
	else if (first < second && second > third && first < third)
	{
		sa(a, data);
		ra(a, data);
	}
	else if (first < second && second > third && first > third)
		rra(a, data);
}

static void	ft_bring_min_to_top(t_stack *a, t_data *data)
{
	int	pos;

	pos = ft_min_pos(a);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a, data);
	}
	else
	{
		while (pos < a->size)
		{
			rra(a, data);
			pos++;
		}
	}
}

void	ft_selection(t_stack *a, t_stack *b, t_data *data)
{
	if (a->size <= 1)
	return ;
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
		sa(a, data);
		return ;
	}
	while (a->size > 3)
	{
		ft_bring_min_to_top(a, data);
		pb(a, b, data);
	}
	ft_sort_three(a, data);
	while (b->size > 0)
    	pa(a, b, data);
}
