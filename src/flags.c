/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:52:06 by tatiana           #+#    #+#             */
/*   Updated: 2026/11/10 12:13:44 by tarebros         ###   ########.fr       */
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

// data is a pointer so the changes are visible in main
// data->start ends on the first number
// returns FALSE on a bad flag or if there are no numbers after the flags

int	ft_parse_flags(int argc, char **argv, t_data *data)
{
	int	flag;

	data->start = 1;
	data->flag = NO_FLAG;
	data->bench = FALSE;
	while (data->start < argc && ft_is_flag(argv[data->start]))
	{
		flag = check_flag(argv[data->start]);
		if (flag != NO_FLAG && data->flag == NO_FLAG)
			data->flag = flag;
		else if (check_bench(argv[data->start]) && !data->bench)
			data->bench = TRUE;
		else
			return (FALSE);
		data->start++;
	}
	if (data->flag == NO_FLAG)
		data->flag = ADAPTIVE;
	return (data->start < argc);
}
