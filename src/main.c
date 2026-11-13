/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:05 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 13:57:43 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	ft_bzero(&data, sizeof(t_data));
	if (!ft_parse_flags(argc, argv, &data))
		return (ft_error());
	if (!ft_get_numbers(argc, argv, &data))
		return (ft_error());
	data.disorder = compute_disorder(data.values, data.size);
	ft_bzero(&b, sizeof(t_stack));
	if (!ft_fill_stack(&a, &data))
	{
		free(data.values);
		return (ft_error());
	}
	ft_dispatcher(&data, &a, &b);
	if (data.bench)
    	print_bench(&data);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	free(data.values);
	return (0);
}
