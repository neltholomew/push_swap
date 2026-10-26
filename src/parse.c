/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:50:01 by pcellar           #+#    #+#             */
/*   Updated: 2026/10/20 15:22:27 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// int is_valid(char *arr)
// {
// 	int	i;
// 	int status;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		status = ft_isdigit(arr[i]);
// 		i++;
// 	}
// 	return (status);
// }
// int	ft_isdup(char *arr)
// {
// 	int i;
// 	int	j;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		j = 0;
// 		while ()
// 		{
// 			if (i == j)
// 				j++;
// 			if (arr[i] == arr[j])
// 				return (ERROR);
// 			j++;
// 		}
// 		i++;
// 	}

// }

void	ft_parse(char *argv, int argc)
{
	char **arr;
	int status;
	int i = 0;

	while (i < argc)
	{
		arr = ft_split(argv, ' ');
		printf("%s", arr[i]);
		i++;
	}
	// status = isvalid(*arr);
	// //ft_atoi()
	// status = ft_isdup(*arr);
}

int main(void)
{
	char *arr[4] = {"1", "2", "3"};
	ft_parse(*arr, 4);
}
