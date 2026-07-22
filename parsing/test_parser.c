/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:27:42 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/22 16:53:52 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"

void	print_tokens(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		printf("[%d] '%s'\n", i, t[i]);
		i++;
	}
	printf("\n----\n\n");
}

void	print_config(t_config cfg)
{
	ft_printf("start: %d\n", cfg.start);

	ft_printf("flag: ");
	if (cfg.flag == FLAG_SIMPLE)
		ft_printf("simple\n");
	else if (cfg.flag == FLAG_MEDIUM)
		ft_printf("medium\n");
	else if (cfg.flag == FLAG_COMPLEX)
		ft_printf("complex\n");
	else if (cfg.flag == FLAG_ADAPTIVE)
		ft_printf("adaptive\n");
	else
		ft_printf("invalid\n");

	ft_printf("bench: ");
	if (cfg.bench == FLAG_BENCH)
		ft_printf("bench is on\n");
	else
		ft_printf("bench is off\n");
}

/*
int main(int argc, char **argv)
{
	t_config cfg;
	char **tokens;

	cfg = parse_config(argc, argv);
	tokens = parse_input(argc, argv, cfg.start);

	if (!tokens)
	{
		printf("ERROR\n");
		return 1;
	}

    //for (int i = 0; argv[i]; i++)
	//    printf("argv[%d] = '%s'\n", i, argv[i]);
    printf("cfg.start = %d\n", cfg.start);
	print_tokens(tokens);
	return 0;
}*/