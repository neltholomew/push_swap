/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:50 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/12 13:37:28 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack *a)
{
	if (!a->top || a->top->next == a->top)
		return ;
	a->top = a->top->next;
	a->bottom = a->bottom->next;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (!b->top || b->top->next == b->top)
		return ;
	b->top = b->top->next;
	b->bottom = b->bottom->next;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a->top || a->top->next == a->top)
		return ;
	a->top = a->top->next;
	a->bottom = a->bottom->next;
	if (!b->top || b->top->next == b->top)
		return ;
	b->top = b->top->next;
	b->bottom = b->bottom->next;
	ft_printf("rr\n");
}
