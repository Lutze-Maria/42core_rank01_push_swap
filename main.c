/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:07:45 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/12 14:42:40 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// initialize stack a & b, point to NULL
	t_stack_node	*a;
	t_stack_node	*b;
	char			is_bench;
	char			**tokens;

	a = NULL;
	b = NULL;
	is_bench = 'n';

	// detect bench flag
	if (argc > 1 && argv[1][0])
		is_bench = check_bench(argv[1]);

	// PARSING
	tokens = parse_input(argc, argv, is_bench);
	if (!tokens)
		return (error());

	// STACK
	stack_init(&a, tokens);
	free_num_array(&tokens);
	if (!a)
		return (error());
	
	// SORTING
	// check: stack a already sorted?
	//		if not:  SORTING ALGORITHM MAGIC  happens here
	//		is_bench flag? if No: use '--adaptive' as default

	// CLEAN UP stack
	free_stack(&a);

	return (0);
}

