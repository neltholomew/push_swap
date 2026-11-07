/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatiana <tatiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:52:06 by tatiana           #+#    #+#             */
/*   Updated: 2026/11/03 18:31:01 by tatiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// check for "--"

int	ft_is_flag(char *arg)
{
	if (!arg || arg[0] != '-' || arg[1] != '-')
		return (FALSE);
	return (TRUE);
}

// if the is flag, check which

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

// check for "--bench"

int	check_bench(char *bench)
{
	if (ft_strncmp(bench, "--bench", 7) == 0 && bench[7] == '\0')
		return (TRUE);
	return (FALSE);
}

// st is a pointer so the changes are visible in main
// st->start ends on the first number
// returns FALSE on a bad flag or if there are no numbers after the flags

int	ft_parse_flags(int argc, char **argv, t_status *st)
{
	int	flag;

	st->start = 1;
	st->flag = NO_FLAG;
	st->bench = FALSE;
	while (st->start < argc && ft_is_flag(argv[st->start]))
	{
		flag = check_flag(argv[st->start]);
		if (flag != NO_FLAG && st->flag == NO_FLAG)
			st->flag = flag;
		else if (check_bench(argv[st->start]) && !st->bench)
			st->bench = TRUE;
		else
			return (FALSE);
		st->start++;
	}
	if (st->flag == NO_FLAG)
		st->flag = ADAPTIVE;
	return (st->start < argc);
}
