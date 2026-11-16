/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stderr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 13:32:45 by pcellar           #+#    #+#             */
/*   Updated: 2026/11/13 13:43:33 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_double_fd(double n, int fd)
{
	int			i;
	long long	whole;
	double		decimal;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	whole = (long long)n;
	decimal = n - (double)whole;
	ft_putnbr_fd(whole, fd);
	ft_putchar_fd('.', fd);
	i = 0;
	while (i < 2)
	{
		decimal *= 10;
		ft_putchar_fd(('0' + (int)decimal % 10), 2);
		i++;
	}
	return ;
}

static void	ft_specifier(char specifier, va_list args)
{
	if (specifier == 's')
		return (ft_putstr_fd(va_arg(args, char *), 2));
	else if (specifier == 'c')
		return (ft_putchar_fd(va_arg(args, int), 2));
	else if (specifier == 'i' || specifier == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 2));
	else if (specifier == '%')
		return (ft_putchar_fd('%', 2));
	else if (specifier == 'f')
		return (ft_double_fd(va_arg(args, double), 2));
	return ;
}

void	ft_printf_stderr(const char *format, ...)
{
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_specifier(format[i], args);
		}
		else
			ft_putchar_fd(format[i], 2);
		i++;
	}
	va_end(args);
	return ;
}
