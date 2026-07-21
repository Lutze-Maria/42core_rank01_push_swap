/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:34:17 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/21 13:19:39 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flag	check_flag(char *flag)
{
	if (!flag)
		return (FLAG_INVALID);
	if (ft_strncmp(flag, "--simple", 9) == 0)
		return (FLAG_SIMPLE);
	if (ft_strncmp(flag, "--medium", 9) == 0)
		return (FLAG_MEDIUM);
	if (ft_strncmp(flag, "--complex", 10) == 0)
		return (FLAG_COMPLEX);
	if (ft_strncmp(flag, "--adaptive", 11) == 0)
		return (FLAG_ADAPTIVE);
	return (FLAG_INVALID);
}

t_config	parse_config(int argc, char **argv)
{
	t_config	cfg;
	t_flag		tmp;

	cfg.flag = FLAG_ADAPTIVE;
	cfg.start = 1;
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == '-')
	{
		tmp = check_flag(argv[1]);
		if (tmp == FLAG_INVALID)
		{
			printf("Flag unknown\n");
			exit(1);
		}
		cfg.flag = tmp;
		cfg.start = 2;
	}
	return (cfg);
}

char	*join_args(int argc, char **argv, int start)
{
	char	*result;
	char	*tmp;
	int		i;

	result = NULL;
	i = start;
	while (i < argc)
	{
		tmp = result;
		result = ft_strjoin(result ? result : "", argv[i]);
		free(tmp);
		if (!result)
			free(result);
		if (i < argc - 1)
		{
			tmp = result;
			result = ft_strjoin(result, " ");
			free(tmp);
			if (!result)
				free(result);
		}
		i++;
	}
	return (result);
}

char	**parse_input(int argc, char **argv, int start)
{
	char	*joined;
	char	**tokens;

	if (argc <= start)
		return (NULL);
	joined = join_args(argc, argv, start);
	if (!joined)
		return (NULL);
	tokens = ft_split(joined, ' ');
	free(joined);
	if (!tokens)
		return (NULL);
	return (tokens);
}

/*
int	main(int argc, char **argv)
{
	t_config	cfg;
	char		**tokens;
	int			i;

	cfg = parse_config(argc, argv);
	tokens = parse_input(argc, argv, cfg.start);
	if (!tokens)
	{
		printf("Error while parsing!\n");
		return (1);
	}
	i = 0;
	while (tokens[i])
	{
		printf("%s\n", tokens[i]);
		i++;
	}
	return (0);
}
*/


// cc -Wall -Wextra -Werror test_parser.c ft_split.c parse_input.c ../libft/libft.a -I../libft -I.. -o push_swap
// chmod +x test.sh
// ./test.sh