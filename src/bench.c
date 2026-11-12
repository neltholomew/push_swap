/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:43:12 by tarebros          #+#    #+#             */
/*   Updated: 2026/11/12 18:22:19 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_bench(t_data	*data)
{
	printf("%d\n", data->bench);
	printf("%f%%\n", data->disorder * 100);
	printf("%d\n", data->flag);

}
