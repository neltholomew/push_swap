/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:52 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 12:29:01 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack *a, t_data *data)
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
	data->total_ops++;
	data->sa++;
	if (data->bench == FALSE)
		ft_printf("sa\n");
}

void	sb(t_stack *b, t_data *data)
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
	data->total_ops++;
	data->sb++;
	if (data->bench == FALSE)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, t_data *data)
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
	data->total_ops++;
	data->ss++;
	if (data->bench == FALSE)
		ft_printf("ss\n");
}
