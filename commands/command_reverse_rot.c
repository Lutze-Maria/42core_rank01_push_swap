/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:29:50 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/23 10:29:55 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// bottom node to top position
/*Before:
head
 ↓
1 <-> 2 <-> 3 <-> 4
  After:
head
 ↓
4 <-> 1 <-> 2 <-> 3
*/

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = find_last_node(*stack);
	if (last->prev)
	{
		last->prev->next = NULL;
		last->prev = NULL;
	}
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack_node **a, bool checker, t_container *container)
{
	rev_rotate(a);
	container->rra++;
	if (checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker, t_container *container)
{
	rev_rotate(b);
	container->rrb++;
	if (checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker,
		t_container *container)
{
	rev_rotate(a);
	rev_rotate(b);
	container->rrr++;
	if (checker)
		write(1, "rrr\n", 4);
}

/*
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_config		cfg;
	char			**tokens;
	bool			silent;

	// initialize stack a & b, point to NULL
	a = NULL;
	b = NULL;
	silent = true;
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
	stack_init(&b, tokens);
	free_num_array(tokens);
	if (!a)
	{
		// printf("Error initiating stack a!\n\n");
		return (1);
	}
	assign_index(a);
	if (!b)
	{
		// printf("Error initiating stack a!\n\n");
		return (1);
	}
	assign_index(b);
	printf("STACK A:");
	print_stack_variant(a);
	printf("STACK B:");
	print_stack_variant(b);
	// RUN COMMAND
	rrr(&a, &b, silent);
	printf("AFTER Command:\n\n");
	printf("STACK A:");
	print_stack_variant(a);
	printf("STACK B:");
	print_stack_variant(b);
	free_stack(&b);
	return (0);
}
*/
