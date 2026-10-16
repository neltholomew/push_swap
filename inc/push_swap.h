/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:02 by pcellar           #+#    #+#             */
/*   Updated: 2026/10/16 18:06:31 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef enum {
	FALSE = 0,
	TRUE
} bool;

typedef enum {
	NO_FLAG = 0,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
} flags;

#endif
