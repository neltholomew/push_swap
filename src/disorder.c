/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:35 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/05 15:02:57 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// total_pairs = size - 1
// small number of arguments

// void	disorder_checker(float disorder, int *status)
// {
// 	if (disorder < 0.2)
// 		status = SIMPLE;
// 	else if (disorder >= 0.2 && disorder <= 0.5)
// 		status = MEDIUM;
// 	else
// 		status = COMPLEX;
// }

float	compute_disorder(int *values, int size, int *status)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = size - 1;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while(j < size && j == (i + 1))
		{
			if (values[i] > values[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	int disorder = mistakes / total_pairs;
	disorder_checker(disorder, &status);
	// printf("DEBUG: mistakes %f\n", mistakes);
	// printf("DEBUG: t_p %f\n", total_pairs);
	return (mistakes / total_pairs);
}

int main()
{
	int values[] = {1, 2, 3};
	int size = 3;
	int status = 3;
	float result;

	result = compute_disorder(values, size, &status);
	printf("disorder %f\n", result);
}
