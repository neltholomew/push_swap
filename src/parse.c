/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:50:01 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/04 16:55:48 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_atoi_safe(char *str, int *out)
{
	int			sign;
	long long	n;

	sign = 1;
	n = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (FALSE);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		n = n * 10 + (*str - '0');
		if ((sign == 1 && n > INT_MAX)
			|| (sign == -1 && n > (long long)INT_MAX + 1))
			return (FALSE);
		str++;
	}
	*out = (int)(n * sign);
	return (TRUE);
}

int	ft_convert_string(char **arr, int **values, int size)
{
	int	i;

	*values = malloc(sizeof(int) * size);
	if (!*values)
		return (FALSE);
	i = 0;
	while (i < size)
	{
		if (!ft_atoi_safe(arr[i], &(*values)[i]))
		{
			free(*values);
			*values = NULL;
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	ft_valid_spacing(char *str)
{
	int	i;

	if (!str || !str[0] || str[0] == ' ')
		return (FALSE);
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && (!str[i + 1] || str[i + 1] == ' '))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	ft_parse_string(char *arg, int **values)
{
	char	**arr;
	int		size;
	int		i;

	if (!ft_valid_spacing(arg))
		return (-1);
	arr = ft_split(arg, ' ');
	if (!arr)
		return (-1);
	size = 0;
	while (arr[size])
		size++;
	if (!ft_convert_string(arr, values, size))
		size = -1;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (size);
}

int	ft_get_numbers(int argc, char **argv, int start, int **values)
{
	int	size;

	*values = NULL;
	if (argc - start == 1)
		size = ft_parse_string(argv[start], values);
	else
	{
		size = argc - start;
		if (!ft_convert_string(argv + start, values, size))
			size = -1;
	}
	if (size > 0 && ft_isdup(*values, size))
	{
		free(*values);
		*values = NULL;
		size = -1;
	}
	return (size);
}
