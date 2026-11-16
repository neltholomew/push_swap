/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:50:01 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/12 10:53:00 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

static int	ft_parse_string(char *arg, int **values, int *size)
{
	char	**arr;
	int		ok;
	int		i;

	if (!ft_valid_spacing(arg))
		return (FALSE);
	arr = ft_split(arg, ' ');
	if (!arr)
		return (FALSE);
	*size = 0;
	while (arr[*size])
		(*size)++;
	ok = ft_convert_string(arr, values, *size);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (ok);
}

int	ft_get_numbers(int argc, char **argv, t_data *data)
{
	data->values = NULL;
	if (argc - data->start == 1)
	{
		if (!ft_parse_string(argv[data->start], &data->values, &data->size))
			data->size = -1;
	}
	else
	{
		data->size = argc - data->start;
		if (!ft_convert_string(argv + data->start, &data->values, data->size))
			data->size = -1;
	}
	if (data->size > 0 && ft_isdup(data->values, data->size))
		data->size = -1;
	if (data->size <= 0)
	{
		free(data->values);
		data->values = NULL;
		return (FALSE);
	}
	return (TRUE);
}
