/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:07:45 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/08 17:23:00 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(int argc, char **argv)
{
	// initialize stack a & b, point to NULL
	t_stack_node	*a;
	t_stack_node	*b;
	char			is_bench;
	int				*numbers;

	a = NULL;
	b = NULL;
	is_bench = 'n';

	// detect bench flag
	if (argc > 1 && argv[1][0])
		is_bench = check_bench(argv[1]);

	// PARSING
	numbers = parse_input(argc, argv, is_bench);
	if (!numbers)
		return (error());

	// STACK
	a = build_stack(numbers, size);
	free(numbers);
	if (!a)
		return (error());
	// SORTING
	// check: stack a already sorted?
	//		if not:  SORTING ALGORITHM MAGIC  happens here
	//		is_bench flag? if No: use '--adaptive' as default

	// CLEAN UP stack

	return (0);
}

