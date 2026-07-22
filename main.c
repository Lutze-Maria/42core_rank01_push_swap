/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:07:45 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/22 15:37:41 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_config		cfg;
	char			**tokens;

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
		printf("Error while parsing!\n");
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
