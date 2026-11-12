/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:42 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/12 13:36:33 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b || !b->top)
		return ;
	node = ft_unlink_node(b);
	ft_link_node(a, node);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !a->top)
		return ;
	node = ft_unlink_node(a);
	ft_link_node(b, node);
	ft_printf("pb\n");
}
