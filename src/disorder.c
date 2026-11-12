/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:52:35 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/12 18:26:50 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_dispatcher(t_data *data, t_stack *a, t_stack *b)
{
	if (data->disorder == 0)
		return ;
	if (data->flag == SIMPLE || (data->flag == ADAPTIVE && (data->size <= 5
				|| data->disorder < 0.2)))
		ft_selection(a, b);
	else if (data->flag == MEDIUM || (data->flag == ADAPTIVE && data->disorder < 0.5))
		ft_chunk(a, b);
	else
		ft_radix(a, b);
}

double	compute_disorder(int *values, int size)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	if (size < 2)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (values[i] > values[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
}
