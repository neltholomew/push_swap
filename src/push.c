/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:42 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 13:22:47 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stack *a, t_stack *b, t_data *data)
{
	t_node	*node;

	if (!b || !b->top)
		return ;
	node = ft_unlink_node(b);
	ft_link_node(a, node);
	data->total_ops++;
	data->pa++;
	if (data->bench == FALSE)
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b, t_data *data)
{
	t_node	*node;

	if (!a || !a->top)
		return ;
	node = ft_unlink_node(a);
	ft_link_node(b, node);
	data->total_ops++;
	data->pb++;
	if (data->bench == FALSE)
		ft_printf("pb\n");
}
