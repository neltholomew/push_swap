/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:02 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 13:59:29 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

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
	double	disorder;
	int		strategy;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_data;

/* parse.c */
int		ft_atoi_safe(char *str, int *out);
int		ft_convert_string(char **arr, int **values, int size);
int		ft_valid_spacing(char *str);
int		ft_get_numbers(int argc, char **argv, t_data *data);

/* fill_stack.c */
int		ft_fill_stack(t_stack *a, t_data *data);

/* lists.c */

t_node	*ft_new_node(int value);
void	ft_add_to_bottom(t_stack *stack, t_node *node);
void	ft_stack_clear(t_stack *stack);
void	ft_link_node(t_stack *stack, t_node *node);
t_node	*ft_unlink_node(t_stack *stack);

/* flags.c */
int		ft_is_flag(char *arg);
int		check_flag(char *flag);
int		check_bench(char *bench);
int		ft_parse_flags(int argc, char **argv, t_data *data);

/* utils.c */
int		ft_isdup(int *values, int size);
int		ft_error(void);

/* ft_printf_stderr/c*/
void	ft_printf_stderr(const char *format, ...);

/* disorder.c */
double	compute_disorder(int *values, int size);
void	ft_dispatcher(t_data *data, t_stack *a, t_stack *b);

/* selection.c */
void	ft_selection(t_stack *a, t_stack *b, t_data *data);
/* chunk.c */
void	ft_chunk(t_stack *a, t_stack *b, t_data *data);

/* radix.c */
void	ft_radix(t_stack *a, t_stack *b, t_data *data);

/* push.c */
void	pa(t_stack *a, t_stack *b, t_data *data);
void	pb(t_stack *a, t_stack *b, t_data *data);

/* swap.c */
void	sa(t_stack *a, t_data *data);
void	sb(t_stack *b, t_data *data);
void	ss(t_stack *a, t_stack *b, t_data *data);

/* rotate.c */
void	ra(t_stack *a, t_data *data);
void	rb(t_stack *b, t_data *data);
void	rr(t_stack *a, t_stack *b, t_data *data);

/* rev_rotate.c */
void	rra(t_stack *a, t_data *data);
void	rrb(t_stack *b, t_data *data);
void	rrr(t_stack *a, t_stack *b, t_data *data);

/* bench.c */
void	print_bench(t_data	*data);

#endif
