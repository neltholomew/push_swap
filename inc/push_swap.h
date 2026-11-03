/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatiana <tatiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:02 by pcellar           #+#    #+#             */
/*   Updated: 2026/10/28 21:32:00 by tatiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
    t_node          *top;
    t_node          *bottom;
    int             size;
}   t_stack;

typedef enum s_bool {
	FALSE = 0,
	TRUE
} t_bool;

typedef enum s_flag {
	NO_FLAG = 0,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
} t_flags;

int	    ft_parse(char *arg, int **values, int *size);
int     ft_valid_spacing(char *str);
int     ft_atoi_safe(char *str, int *out);
int     ft_isdup(int *values, int size);
void    ft_free_split(char **arr);
int	    ft_convert_string(char **arr, int **values, int size);

int     check_flag(char *flag);
int     check_bench(char *bench);
int     ft_is_flag(char *arg);
void	ft_dispatch(t_stack *a, t_stack *b, int status);

int	ft_has_space(char *str);

#endif
