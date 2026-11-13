/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:43:12 by tarebros          #+#    #+#             */
/*   Updated: 2026/11/13 13:18:37 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_print_strategy(t_data *data)
{
	char	*strategy;
	if (data->flag == SIMPLE)
		strategy = "Simple / O(n2)";
	else if (data->flag == MEDIUM)
		strategy = "Medium / O(n√n)";
	else if (data->flag == COMPLEX)
		strategy = "Complex / O(n log n)";
	else if (data->flag == ADAPTIVE && (data->size <= 5
				|| data->disorder < 0.2))
		strategy = "Adaptive / O(n2)";
	else if (data->flag == ADAPTIVE && data->disorder < 0.5)
		strategy = "Adaptive / O(n√n)";
	else
		strategy = "Adaptive / O(n log n)";
	return (strategy);
}

void	print_bench(t_data	*data)
{
	char *str;

	str = ft_print_strategy(data);
	// ft_printf("[bench] disorder: %f%%\n", data->disorder * 100);
	ft_printf("[bench] strategy: %s\n", str);
	ft_printf("[bench] total_ops: %d\n", data->total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		data->sa, data->sb, data->ss, data->pa, data->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		data->ra, data->rb, data->rr, data->rra, data->rrb, data->rrr);
}
