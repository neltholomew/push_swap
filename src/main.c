/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatiana <tatiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:05 by pcellar           #+#    #+#             */
/*   Updated: 2026/10/28 21:31:07 by tatiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	ft_has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	main(int argc, char **argv)
{
	int	status;
	int	bench;
	int	start;

	if (argc == 1)
		return (0);
	if (!ft_parse_flags(argc, argv, &status, &bench, &start))
		return (ft_error());
	if (start == argc)
		return (ft_error());
	/* Parse numbers, build stacks, then sort. */
	return (0);
}
