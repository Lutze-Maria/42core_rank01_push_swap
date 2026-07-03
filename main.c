/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:07:45 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/02 15:40:52 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// initialize stack a & b, point to NULL
	t_stack_node	*a;
	//t_stack_node	*b;
	t_config 		cfg;
	char			**tokens;

	a = NULL;
	//b = NULL;
	
	// detect flag + PARSING
	cfg = parse_config(argc, argv);
    tokens = parse_input(argc, argv, cfg.start);
	if (!tokens)
    {
        printf("Error while parsing!\n");
        return (1);
    }
	
	// STACK
	stack_init(&a, tokens);
	if (!a)
	{
        // printf("Error initiating stack a!\n\n");
        return (1);
    }
	assign_index(a);
	
	free_num_array(tokens);
	
	print_stack(a);
	
	// SORTING
	// check: stack a already sorted?
	//		if not:  SORTING ALGORITHM MAGIC  happens here
	//		is_bench flag? if No: use '--adaptive' as default

	
	// CLEAN UP stack
	free_stack(&a);

	return (0);
}
