/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:34:17 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/12 15:34:31 by lschawer         ###   ########.fr       */
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

int	is_only_spaces(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return (0);
	return (1);
}

int	contains_space(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_dup_argv(int argc, char **argv, char is_bench)
{
	//counts arguments
	//allocates new char **
	//duplicates strings with ft_strdup
	//NULL-terminates properly
	char	**tokens;
	int		i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		ft_strdup(token[i]; argv[i])
		i++;
	}
	tokens[i] = '\0';
	return (tokens);
}

char	**parse_input(int argc, char **argv, char is_bench)
{
	int		start;
	char	**tokens;

	// determine where numeric arguments start
	start = (is_bench != 'n') ? 2 : 1;

	// no input at all (with o without bench)
	if (argc <= start || !argv[start] || argv[start][0] == '\0')
		return (NULL);

	// reject empty str or string with only ' '
	if (!argv[start] || argv[start][0] == '\0' || is_only_spaces(argv[start]))
		return (NULL);

	// case 1: single string that needs splitting
	if (argc - start == 1 && contains_space(argv[start]))
	{
		tokens = ft_split(argv[start], ' ');
		if (!tokens)
			return (NULL);
		return (tokens);
	}

	// case 2: already separated arguments
	tokens = ft_dup_argv(&argv[start]);
	if (!tokens)
		return (NULL);
	return (tokens);
}



// TEST check_bench only
/* 
int	main(int argc, char *argv[])
{
	char	*bench;

	bench = check_bench(argv[1]);
	printf("Bench flag used: %s\n", bench);
	return (0);
}
 */

// TEST check_norm_input
int	main(int argc, char *argv[])
{
	int		i;
	int		is_bench;
	char	**numbers;

	is_bench = 'n';
	if (argc > 1)
		is_bench = check_bench(argv[1]);
	numbers = collect_input(argc, argv, is_bench);
	i = 0;
	while (numbers[i])
	{
		printf("%s\n", numbers[i]);
		i++;
	}
	return (0);
}





