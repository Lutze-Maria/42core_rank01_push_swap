/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:34:17 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/07 18:42:18 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

char	check_bench(char *bench)
{
	if (ft_strncmp(bench, "--simple", 8) == 0)
		return ('s');
	if (ft_strncmp(bench, "--medium", 8) == 0)
		return ('m');
	if (ft_strncmp(bench, "--complex", 9) == 0)
		return ('c');
	if (ft_strncmp(bench, "--adaptive", 10) == 0)
		return ('a');
	else
		return ('n');
}

char	**check_norm_input(int argc, char **argv, char is_bench)
{
	// no user input at all, or only empty string
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	//If yes:
	//	is there data after it?
	//	is data one string or multiple arguments?
	if (is_bench != 'n')
	{
		if (argc == 2 || (argc == 3 && !argv[2][0]))
			return (NULL);
		else if (argc == 3 && argv[2][0])
			return (ft_split(argv[2]));
		else
			return (argv + 2);
	}
	//If no:
	//	is there data?
	//	is data one string or multiple arguments?
	else
	{
		if (argc == 2 && argv[1][0])
			return (ft_split(argv[1]));
		else
			return (argv + 1);
	}
}


// check_bench test
/*
int	main(int argc, char *argv[0])
{
	char	*bench;

	bench = check_bench(argv[1]);
	printf("Bench flag used: %s\n", bench);
	return (0);
}
*/
