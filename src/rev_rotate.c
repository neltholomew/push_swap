/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:46 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 13:56:09 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void rev_rotate_top(t_stack *s)
{
    if (!s->top || s->top->prev == s->top)
        return ;
    s->top = s->top->prev;
    s->bottom = s->bottom->prev;
}

void    rra(t_stack *a, t_data *data)
{
    rev_rotate_top(a);
    data->total_ops++;
    data->rra++;
    if (data->bench == FALSE)
        ft_printf("rra\n");
}

void    rrb(t_stack *b, t_data *data)
{
    rev_rotate_top(b);
    data->total_ops++;
    data->rrb++;
    if (data->bench == FALSE)
        ft_printf("rrb\n");
}

void    rrr(t_stack *a, t_stack *b, t_data *data)
{
    rev_rotate_top(a);
    rev_rotate_top(b);
    data->total_ops++;
    data->rrr++;
    if (data->bench == FALSE)
        ft_printf("rrr\n");
}
