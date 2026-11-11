/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:42 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/11 14:58:04 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	unlink_node(t_stack *s1)
{
	t_node	*node;

	node = s1->top;
	if (s1->top->next == s1->top)
		s1->top = NULL;
	else
	{
		s1->top->next = s1->top;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	s1->size--;
}

static void	link_node(t_stack *s2, t_node *node)
{
	if (!s2->top)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next =
	}


}

static void	push_node(t_stack *s1, t_stack *s2)
{
	t_node	*node;

	node = s1->top;
	unlink_node(s1);
	link_node(s2, node);
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b->top)
		return ;
	push_node(b, a);

}


void	pb(t_stack *a, t_stack *b);
