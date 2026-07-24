/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:34:17 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/24 09:57:02 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_config_flag(t_config *cfg, char *arg)
{
	t_flag	tmp_flag;
	t_bench	tmp_bench;

	tmp_flag = check_flag(arg);
	tmp_bench = check_bench(arg);
	if (tmp_flag == FLAG_INVALID && tmp_bench == FLAG_BENCH)
		cfg->bench = tmp_bench;
	if (tmp_flag != FLAG_INVALID && tmp_bench == FLAG_BENCH_INVALID)
		cfg->flag = tmp_flag;
}

t_config	parse_config(int argc, char **argv)
{
	t_config	cfg;
	int			i;

	cfg.flag = FLAG_ADAPTIVE;
	cfg.bench = FLAG_BENCH_INVALID;
	cfg.start = 1;
	i = 1;
	while (i < argc && i <= 2)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			set_config_flag(&cfg, argv[i]);
			cfg.start++;
		}
		i++;
	}
	return (cfg);
}

char	*join_args(int argc, char **argv, int start)
{
	char	*result;
	char	*tmp;
	int		i;

	result = ft_strdup("");
	i = start;
	while (i < argc)
	{
		tmp = ft_strjoin(result, argv[i]);
		free(result);
		result = tmp;
		if (!result)
			return (NULL);
		if (i < argc - 1)
		{
			tmp = ft_strjoin(result, " ");
			free(result);
			result = tmp;
			if (!result)
				return (NULL);
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
