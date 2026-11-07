/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatiana <tatiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:05 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/06 18:40:59 by tatiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_status	st;
	t_stack		a;
	t_stack		b;

	if (argc == 1)
		return (0);
	ft_bzero(&st, sizeof(t_status));
	if (!ft_parse_flags(argc, argv, &st))
		return (ft_error());
	if (!ft_get_numbers(argc, argv, &st))
		return (ft_error());
	st.disorder = compute_disorder(st.values, st.size);
	// build stacks a and b here fill_stack
	ft_dispatcher(&st, &a, &b);
	free(st.values);
	return (0);
}
