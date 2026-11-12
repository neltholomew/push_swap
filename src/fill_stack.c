/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 10:51:01 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/12 11:41:28 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// rank of value = how many values are smaller than it (0 to size - 1)

static int	ft_get_rank(int *values, int size, int value)
{
	int	rank;
	int	i;

	rank = 0;
	i = 0;
	while (i < size)
	{
		if (values[i] < value)
			rank++;
		i++;
	}
	return (rank);
}

// builds stack a from data->values, first value ends up on top
// each node also gets its normalized index

int	ft_fill_stack(t_stack *a, t_data *data)
{
	t_node	*node;
	int		i;

	// makes sure the stack isnt filled with garbage values
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	i = 0;
	while (i < data->size)
	{
		node = ft_new_node(data->values[i]);
		if (!node)
		{
			ft_stack_clear(a);
			return (FALSE);
		}
		node->index = ft_get_rank(data->values, data->size, node->value);
		ft_add_to_bottom(a, node);
		i++;
	}
	return (TRUE);
}



void	ft_add_to_bottom(t_stack *stack, t_node *node);
// if (!stack->top) to see if the stack is empty
// should add a->size += 1
void	ft_stack_clear(t_stack *stack);
