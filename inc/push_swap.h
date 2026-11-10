/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarebros <tarebros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:02 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/10 14:32:03 by tarebros         ###   ########.fr       */
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

typedef struct s_data
{
	int		flag;
	int		bench;
	int		*values;
	int		size;
	int		start;
	float	disorder;
}	t_data;

/* parse.c */
int		ft_atoi_safe(char *str, int *out);
int		ft_convert_string(char **arr, int **values, int size);
int		ft_valid_spacing(char *str);
int		ft_get_numbers(int argc, char **argv, t_data *data);

/* fill_stack.c */
int		ft_fill_stack(t_stack *a, t_data *data);

/* lists.c */

t_node	*new_node(int value);
t_stack new_stack(int size, t_node *top);

/* flags.c */
int		ft_is_flag(char *arg);
int		check_flag(char *flag);
int		check_bench(char *bench);
int		ft_parse_flags(int argc, char **argv, t_data *data);

/* utils.c */
int		ft_isdup(int *values, int size);
int		ft_error(void);

/* disorder.c */
float	compute_disorder(int *values, int size);
void	ft_dispatcher(t_data *data, t_stack *a, t_stack *b);

/* chunk.c */
void	ft_chunk(t_stack *a, t_stack *b);



#endif
