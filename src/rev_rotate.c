/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:46 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/12 13:37:14 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stack *a)
{
	if (!a->top || a->top->prev == a->top)
		return ;
	a->top = a->top->prev;
	a->bottom = a->bottom->prev;
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (!b->top || b->top->prev == b->top)
		return ;
	b->top = b->top->prev;
	b->bottom = b->bottom->prev;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a->top || a->top->prev == a->top)
		return ;
	a->top = a->top->prev;
	a->bottom = a->bottom->prev;
	if (!b->top || b->top->prev == b->top)
		return ;
	b->top = b->top->prev;
	b->bottom = b->bottom->prev;
	ft_printf("rrr\n");
}
