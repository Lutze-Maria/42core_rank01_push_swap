/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:34:17 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/24 12:58:31 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	set_config_flag(t_config *cfg, char *arg)
{
	t_flag	tmp_flag;
	t_bench	tmp_bench;

	tmp_flag = check_flag(arg);
	tmp_bench = check_bench(arg);
	if (tmp_flag != NO_FLAG)
	{
		if (cfg->flag != NO_FLAG)
			return (1);
		cfg->flag = tmp_flag;
	}
	else if (tmp_bench != NO_FLAG_BENCH)
	{
		if (cfg->bench == FLAG_BENCH)
			return (1);
		cfg->bench = FLAG_BENCH;
	}
	else
		return (1);
	return (0);
}

t_config	parse_config(int argc, char **argv)
{
	t_config	cfg;
	int			i;

	cfg.flag = NO_FLAG;
	cfg.bench = NO_FLAG_BENCH;
	cfg.start = 1;
	i = 1;
	while (i < argc && i <= 2)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (set_config_flag(&cfg, argv[i]) == 1)
			{
				ft_printf(2, "Error\n");
				exit(EXIT_FAILURE);
			}
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
