/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:50 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 12:29:08 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack *a, t_data *data)
{
	if (!a->top || a->top->next == a->top)
		return ;
	a->top = a->top->next;
	a->bottom = a->bottom->next;
	data->total_ops++;
	data->ra++;
	if (data->bench == FALSE)
		ft_printf("ra\n");
}

void	rb(t_stack *b, t_data *data)
{
	if (!b->top || b->top->next == b->top)
		return ;
	b->top = b->top->next;
	b->bottom = b->bottom->next;
	data->total_ops++;
	data->rb++;
	if (data->bench == FALSE)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b, t_data *data)
{
	if (!a->top || a->top->next == a->top)
		return ;
	a->top = a->top->next;
	a->bottom = a->bottom->next;
	if (!b->top || b->top->next == b->top)
		return ;
	b->top = b->top->next;
	b->bottom = b->bottom->next;
	data->total_ops++;
	data->rr++;
	if (data->bench == FALSE)
		ft_printf("rr\n");
}
