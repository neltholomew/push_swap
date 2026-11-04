/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:05 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/04 18:16:01 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_dipatcher(int bench, int status, int *values, int size)
{
	if (bench == TRUE)
		ft_bench();
	if (status == SIMPLE)
		ft_insertion();
	else if (status == MEDIUM)
		ft_chunk();
	else if (status == COMPLEX)
		ft_radix();
	else
		compute_disorder(values, size, &status);
		// total_pairs = size - 1
		// small number of arguments
}

int	main(int argc, char **argv)
{
	int	status;
	int	bench;
	int	start;
	int	size;
	int	*values;
	int i;

	if (argc == 1)
		return (0);
	start = ft_parse_flags(argc, argv, &status, &bench);
	// printf("start = %d\n", start);
	// printf("bench = %d\n", bench);
	// printf("status = %d\n", status);
	if (start < 0 || start == argc)
		return (ft_error());
	size = ft_get_numbers(argc, argv, start, &values);
	while (i < size)
		printf("values = %d\n", values[i++]);
	printf("size = %d\n", size);
	if (size < 0)
		return (ft_error());
	ft_dipatcher(bench, &status, values, size);
	free(values);
	return (0);
}
