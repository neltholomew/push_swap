/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:05 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/04 12:08:23 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int	status;
	int	bench;
	int	start;
	int	size;
	int	*values;

	if (argc == 1)
		return (0);
	start = ft_parse_flags(argc, argv, &status, &bench);
	printf("start = %d\n", start);
	printf("bench = %d\n", bench);
	printf("status = %d\n", status);
	if (start < 0 || start == argc)
		return (ft_error());
	size = ft_get_numbers(argc, argv, start, &values);
	printf("size = %d\n", size);
	if (size < 0)
		return (ft_error());
	free(values);
	return (0);
}
