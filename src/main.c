/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcellar <pcellar@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:23:05 by pcellar           #+#    #+#             */
/*   Updated: 2026/10/16 18:23:50 by pcellar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_bench(char *bench)
{
	if (ft_strncmp(bench, "--bench", 8) == 0)
		return (TRUE);
	return (FALSE);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n && s1[i] != '\0' && s2[i] != '\0')
// 	{
// 		if (s1[i] != s2[i])
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		i++;
// 	}
// 	if (i < n)
// 		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 	return (0);
// }


int check_flag(char *flag)
{
	if (ft_strncmp(flag, "--simple", 9) == 0)
		return (SIMPLE);
	if (ft_strncmp(flag, "--medium", 10) == 0)
		return (MEDIUM);
	if (ft_strncmp(flag, "--complex", 10) == 0)
		return (COMPLEX);
	if (ft_strncmp(flag, "--adaptive", 11) == 0)
		return (ADAPTIVE);
	return (NO_FLAG);
}

int	main(int argc, char *argv[])
{
	int	bench;
	int	flag;

	// int result = 0;
	// result = check_flag("--simple");
	// printf("%d\n", result);

	// result = check_flag("--medium");
	// printf("%d\n", result);

	// result = check_flag("--complex");
	// printf("%d\n", result);

	// result = check_flag("--adaptive");
	// printf("%d\n", result);

	// result = check_flag("adsd");
	// printf("%d\n", result);

	if (argc < 2)
	return (0);
	bench = check_bench(argv[1]);
	if (bench == TRUE)
	flag = check_flag(argv[2]);
	else
	flag = check_flag(argv[1]);
	//parse()




}
