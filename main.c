/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:07:45 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/07 18:45:13 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(int argc, char **argv)
{
	// initialize stack a & b, point to NULL
	t_stack_node	a;
	t_stack_node	b;
	char			is_bench;
	char			**num_array;

	a = NULL;
	b = NULL;
	is_bench = 'n';

	// detect bench flag
	if (argc > 1 && argv[1][0])
		is_bench = check_bench(argv[1]);
	// check for input errors, normalize input into num_array
	num_array = check_norm_input(argc, argv, is_bench)

	// Initialize stack a, by appending each input number as a node
	//		handle int overflow, duplicates, syntax errors
	//		e.g. input must only contain digits, '-', '+'
	//			if errors found: free stack a, return "Error"
	//		check each input: must be long integer 
	// 			if string: convert (those from ft_split are still str)
	//		all conditions met: append node

	// check: stack a already sorted?
	//		if not: SORTING ALGO MAGIC happens here
	//		is_bench flag? if not use '--adaptive'

	// Clean up the stack

	return (0);
}

