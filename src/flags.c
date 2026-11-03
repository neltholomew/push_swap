/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatiana <tatiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:52:06 by tatiana           #+#    #+#             */
/*   Updated: 2026/10/28 21:19:20 by tatiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_flag(char *arg)
{
	if (!arg || arg[0] != '-' || arg[1] != '-')
		return (FALSE);
	return (TRUE);
}

int	check_flag(char *flag)
{
	if (ft_strncmp(flag, "--simple", 8) == 0 && flag[8] == '\0')
		return (SIMPLE);
	if (ft_strncmp(flag, "--medium", 8) == 0 && flag[8] == '\0')
		return (MEDIUM);
	if (ft_strncmp(flag, "--complex", 9) == 0 && flag[9] == '\0')
		return (COMPLEX);
	if (ft_strncmp(flag, "--adaptive", 10) == 0 && flag[10] == '\0')
		return (ADAPTIVE);
	return (NO_FLAG);
}

int	check_bench(char *bench)
{
	if (ft_strncmp(bench, "--bench", 7) == 0 && bench[7] == '\0')
		return (TRUE);
	return (FALSE);
}

void	ft_dispatch(t_stack *a, t_stack *b, int status)
{
	if (status == SIMPLE)
		ft_simple_sort(a, b);
	else if (status == MEDIUM)
		ft_medium_sort(a, b);
	else if (status == COMPLEX)
		ft_complex_sort(a, b);
	else
		ft_adaptive_sort(a, b);
}

int	ft_parse_flags(int argc, char **argv, int *status, int *bench, int *start)
{
	int	i;
	int	flag;
	int	has_strategy;

	i = 1;
	*status = ADAPTIVE;
	*bench = FALSE;
	has_strategy = FALSE;
	while (i < argc && ft_is_flag(argv[i]))
	{
		flag = check_flag(argv[i]);
		if (flag != NO_FLAG && !has_strategy)
			*status = flag;
		else if (flag != NO_FLAG)
			return (0);
		else if (check_bench(argv[i]) && !*bench)
			*bench = TRUE;
		else
			return (0);
		if (flag != NO_FLAG)
			has_strategy = TRUE;
		i++;
	}
	*start = i;
	return (1);
}