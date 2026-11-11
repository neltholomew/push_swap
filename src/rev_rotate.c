/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:46 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/11 14:29:35 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stack *a)
{
	if (!a->top || a->top->prev == a->top)
		return ;
	a->top = a->top->prev;
}

void	rrb(t_stack *b)
{
	if (!b->top || b->top->prev == b->top)
		return ;
	b->top = b->top->prev;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
