/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:43:12 by tarebros          #+#    #+#             */
/*   Updated: 2026/11/13 12:49:46 by tarebros         ###   ########.fr       */
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
	ft_printf("[bench] strategy: %s", str);


	// printf("bench = %d\n", data->bench);
	// printf("disorder = %f%%\n", data->disorder * 100);
	// printf("flag = %d\n", data->flag);
	// printf("total_ops = %d\n", data->total_ops);
	// printf("pa = %d\n", data->pa);
	// printf("pb = %d\n", data->pb);
	// printf("sa = %d\n", data->sa);
	// printf("sb = %d\n", data->sb);
	// printf("ss = %d\n", data->ss);
	// printf("ra = %d\n", data->ra);
	// printf("rb = %d\n", data->rb);
	// printf("rr = %d\n", data->rr);
	// printf("rra = %d\n", data->rra);
	// printf("rrb = %d\n", data->rrb);
	// printf("rrr = %d\n", data->rrr);
}
