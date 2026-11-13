/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:46 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 12:29:14 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stack *a, t_data *data)
{
	if (!a->top || a->top->prev == a->top)
		return ;
	a->top = a->top->prev;
	a->bottom = a->bottom->prev;
	data->total_ops++;
	data->rra++;
	if (data->bench == FALSE)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, t_data *data)
{
	if (!b->top || b->top->prev == b->top)
		return ;
	b->top = b->top->prev;
	b->bottom = b->bottom->prev;
	data->total_ops++;
	data->rrb++;
	if (data->bench == FALSE)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, t_data *data)
{
	if (!a->top || a->top->prev == a->top)
		return ;
	a->top = a->top->prev;
	a->bottom = a->bottom->prev;
	if (!b->top || b->top->prev == b->top)
		return ;
	b->top = b->top->prev;
	b->bottom = b->bottom->prev;
	data->total_ops++;
	data->rrr++;
	if (data->bench == FALSE)
		ft_printf("rrr\n");
}
