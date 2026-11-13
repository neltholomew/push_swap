/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:52 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 13:55:22 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void swap_top(t_stack *s)
{
    int tmp;

    if (!s->top || s->top->next == s->top)
        return ;
    tmp = s->top->index;
    s->top->index = s->top->next->index;
    s->top->next->index = tmp;
}

void	sa(t_stack *a, t_data *data)
{
	swap_top(a);
	data->total_ops++;
	data->sa++;
	if (data->bench == FALSE)
	ft_printf("sa\n");
}

void	sb(t_stack *b, t_data *data)
{
	swap_top(b);
	data->total_ops++;
	data->sb++;
	if (data->bench == FALSE)
	ft_printf("sb\n");
}

void    ss(t_stack *a, t_stack *b, t_data *data)
{
	swap_top(a);
	swap_top(b);
	data->total_ops++;
	data->ss++;
	if (data->bench == FALSE)
		ft_printf("ss\n");
}
