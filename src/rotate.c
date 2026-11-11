/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:50 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/11 14:29:18 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack *a)
{
	if (!a->top || a->top->next == a->top)
		return ;
	a->top = a->top->next;
}

void	rb(t_stack *b)
{
	if (!b->top || b->top->next == b->top)
		return ;
	b->top = b->top->next;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
