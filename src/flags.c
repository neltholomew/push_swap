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

// status and bench are pointers to change the value in main
// i returns where numbers start

int	ft_parse_flags(int argc, char **argv, int *status, int *bench)
{
	int	i;
	int	flag;

	i = 1;
	*status = NO_FLAG;
	*bench = FALSE;
	while (i < argc && ft_is_flag(argv[i]))
	{
		flag = check_flag(argv[i]);
		if (flag != NO_FLAG && *status == NO_FLAG)
			*status = flag;
		else if (check_bench(argv[i]) && !*bench)
			*bench = TRUE;
		else
			return (-1);
		i++;
	}
	if (*status == NO_FLAG)
		*status = ADAPTIVE;
	return (i);
}
