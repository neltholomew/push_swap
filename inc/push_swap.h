/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:02 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/05 18:28:13 by tarebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef enum e_bool
{
	FALSE = 0,
	TRUE
}	t_bool;

typedef enum e_flag
{
	NO_FLAG = 0,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_flags;

/* parse.c */
int		ft_atoi_safe(char *str, int *out);
int		ft_convert_string(char **arr, int **values, int size);
int		ft_valid_spacing(char *str);
int		ft_get_numbers(int argc, char **argv, int start, int **values);

/* flags.c */
int		ft_is_flag(char *arg);
int		check_flag(char *flag);
int		check_bench(char *bench);
int		ft_parse_flags(int argc, char **argv, int *status, int *bench);

/* utils.c */
int		ft_isdup(int *values, int size);
int		ft_error(void);

/* main.c */
void	ft_dispatcher(int bench, int status, int *values, int size);
#endif
