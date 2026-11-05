/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:05 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/05 20:22:41 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_dispatcher(int flag, int *values, t_stack a, int size)
{
	float	disorder;

	if (size >= 3 && size <= 5)
		ft_insertion(a, size);
	if (flag == SIMPLE)
		ft_insertion(a, size);
	else if (flag == MEDIUM)
		ft_chunk(a, size);
	else if (flag == COMPLEX)
		ft_radix(a, size);
	else if (flag == ADAPTIVE || flag == NO_FLAG)
		disorder = compute_disorder(values, size, &flag);
	if (disorder < 0.2)
		ft_insertion(a, size);
	else if (disorder >= 0.2 && disorder <= 0.5)
		ft_chunk(a, size);
	else
		ft_radix(a, size);
}

int	main(int argc, char **argv)
{
	int		flag;
	int		bench;
	int		start;
	int		size;
	int		*values;
	t_stack	a;
	// int i;

	if (argc == 1)
		return (0);
	start = ft_parse_flags(argc, argv, &flag, &bench);
	// printf("start = %d\n", start);
	// printf("bench = %d\n", bench);
	// printf("flag = %d\n", flag);
	if (start < 0 || start == argc)
		return (ft_error());
	size = ft_get_numbers(argc, argv, start, &values);
	// while (i < size)
	// 	printf("values = %d\n", values[i++]);
	// printf("size = %d\n", size);
	if (size < 0)
		return (ft_error());
	// if (bench == TRUE)
	// 	ft_bench();
	fill_stack();
	ft_dipatcher(&flag, values, a, size);
	free(values);
	return (0);
}
