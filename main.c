/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:07:45 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/23 11:31:36 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_config		cfg;
	char			**tokens;

	ft_printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++)
    	ft_printf("argv[%d] = '%s'\n", i, argv[i]);
	// initialize stack a & b, point to NULL
	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	// detect flag + PARSING
	cfg = parse_config(argc, argv);
	tokens = parse_input(argc, argv, cfg.start);
	if (!tokens)
	{
		ft_printf("Error while parsing!\n");
		return (1);
	}
	// STACK
	// stack_init(&a, tokens);
	if (stack_init(&a, tokens))
	{
		free_num_array(tokens);
		return (1);
	}
	free_num_array(tokens);
	if (!a)
	{
		// printf("Error initiating stack a!\n\n");
		return (1);
	}
	assign_index(a);
	// free_num_array(tokens);
	print_stack(a);
	// SORTING
	// check: stack a already sorted?
	//		if not:  SORTING ALGORITHM MAGIC  happens here
	sort_stack(&a, cfg, compute_disorder(&a));
	// CLEAN UP stack
	free_stack(&a);
	return (0);
}

// chmod +x test.sh
// ./test.sh

// ./push_swap --medium --bench 7211 2641 9992 1374 3166 6081 2041 7995 8378 777

// ./push_swap 1 2 3 6 5 4 7 8 9 13 12 11 14 16 15 18 17 19 50 40 60 20 80 90 10
// ./push_swap --bench 1 2 3 6 5 4 7 8 9 13 12 11 14 16 15 18 17 19 50 40 60 20 80 90 10
// ./push_swap --bench 100 200 600 500 400 800 900 1200 1100 170000 1400 800000 1600 1500 1800 1700 1900 5000 4000 6000 2000 8000 9000 1000 10000 20000 30000 700 60000 50000 40000 1300 400000 70000 300 80000 90000 130000 120000 110000 140000 150000 180000 190000 500000 600000 200000 900000 100000 160000