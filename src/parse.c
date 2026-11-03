/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatiana <tatiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:50:01 by pcellar           #+#    #+#             */
/*   Updated: 2026/10/28 21:35:52 by tatiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_free_values(int **values)
{
	if (*values)
		free(*values);
	*values = NULL;
}

void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

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

int	ft_isdup(int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	ft_parse(char *arg, int **values, int *size)
{
	char	**arr;
	int		count;

	*values = NULL;
	*size = 0;
	if (!ft_valid_spacing(arg))
		return (FALSE);
	arr = ft_split(arg, ' ');
	if (!arr)
		return (FALSE);
	count = 0;
	while (arr[count])
		count++;
	if (!ft_convert_string(arr, values, count))
	{
		ft_free_split(arr);
		return (FALSE);
	}
	ft_free_split(arr);
	if (ft_isdup(*values, count))
	{
		free(*values);
		*values = NULL;
		return (FALSE);
	}
	*size = count;
	return (TRUE);
}
