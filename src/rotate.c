/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:50 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 13:55:56 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void rotate_top(t_stack *s)
{
    if (!s->top || s->top->next == s->top)
        return ;
    s->top = s->top->next;
    s->bottom = s->bottom->next;
}

void    ra(t_stack *a, t_data *data)
{
    rotate_top(a);
    data->total_ops++;
    data->ra++;
    if (data->bench == FALSE)
        ft_printf("ra\n");
}

void    rb(t_stack *b, t_data *data)
{
    rotate_top(b);
    data->total_ops++;
    data->rb++;
    if (data->bench == FALSE)
        ft_printf("rb\n");
}

void    rr(t_stack *a, t_stack *b, t_data *data)
{
    rotate_top(a);
    rotate_top(b);
    data->total_ops++;
    data->rr++;
    if (data->bench == FALSE)
        ft_printf("rr\n");
}
