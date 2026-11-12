/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:13:13 by tarebros          #+#    #+#             */
/*   Updated: 2026/11/12 13:36:19 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*ft_new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_add_to_bottom(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (!stack->top)
	{
		node->next = node;
		node->prev = node;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->prev = stack->bottom;
		node->next = stack->top;
		stack->bottom->next = node;
		stack->top->prev = node;
		stack->bottom = node;
	}
	stack->size++;
}

void	ft_stack_clear(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;

	if (!stack || !stack->top)
		return ;
	curr = stack->top;
	while (stack->size > 0)
	{
		next = curr->next;
		free(curr);
		curr = next;
		stack->size--;
	}
	stack->top = NULL;
	stack->bottom = NULL;
}

void	ft_link_node(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (!stack->top)
	{
		node->next = node;
		node->prev = node;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->prev = stack->bottom;
		node->next = stack->top;
		stack->bottom->next = node;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

t_node	*ft_unlink_node(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = node->next;
		stack->bottom->next = stack->top;
		stack->top->prev = stack->bottom;
	}
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}
