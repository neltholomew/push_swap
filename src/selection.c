/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:37 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/17 12:19:22 by pcellar          ###   ########.fr       */
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

static int	ft_is_sorted(t_stack *a)
{
	t_node	*curr;
	int		i;

	if (a->size <= 1)
		return (TRUE);
	curr = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		if (curr->index > curr->next->index)
			return (FALSE);
		curr = curr->next;
		i++;
	}
	return (TRUE);
}

void	ft_selection(t_stack *a, t_stack *b, t_data *data)
{
	if (a->size <= 1 || ft_is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a, data);
		return ;
	}
	while (a->size > 3 && !ft_is_sorted(a))
	{
		ft_bring_min_to_top(a, data);
		if (ft_is_sorted(a))
			break ;
		pb(a, b, data);
	}
	if (!ft_is_sorted(a))
		ft_sort_three(a, data);
	while (b->size > 0)
		pa(a, b, data);
}
