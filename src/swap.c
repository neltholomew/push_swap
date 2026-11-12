/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:52 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/12 12:08:26 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (!a->top || a->top->next == a->top)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
	tmp = a->top->index;
	a->top->index = a->top->next->index;
	a->top->next->index = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	int	tmp;

	if (!b->top || b->top->next == b->top)
		return ;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
	tmp = b->top->index;
	b->top->index = b->top->next->index;
	b->top->next->index = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (!a->top || a->top->next == a->top)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
	tmp = a->top->index;
	a->top->index = a->top->next->index;
	a->top->next->index = tmp;
	if (!b->top || b->top->next == b->top)
		return ;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
	tmp = b->top->index;
	b->top->index = b->top->next->index;
	b->top->next->index = tmp;
	ft_printf("ss\n");
}
