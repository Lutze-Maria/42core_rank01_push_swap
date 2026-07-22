/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:55:39 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/22 10:55:42 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// top node to bottom position

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;

	first = *stack;
	last = find_last_node(*stack);

	*stack = first->next;
	(*stack)->prev = NULL;

	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **a, bool checker, t_container container)
{
	rotate(a);
	container.ra++;
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool checker, t_container container)
{
	rotate(b);
	container.rb++;
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker, t_container container)
{
	rotate(a);
	rotate(b);
	container.rr++;
	if (!checker)
		write(1, "rr\n", 3);
}
/*
int	main(int argc, char **argv)
{
	// initialize stack a & b, point to NULL
	//t_stack_node	*a;
    t_stack_node	*b;
	t_config 		cfg;
	char			**tokens;
    bool            silent;

    //a = NULL;
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
    //stack_init(&a, tokens);
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

	//printf("STACK A:");
	//print_stack_variant(a);
	printf("STACK B:");
	print_stack(b);

	// RUN COMMAND
    rb(&b, silent);
	rb(&b, silent);
	rb(&b, silent);
	rb(&b, silent);

    printf("AFTER Command:\n\n");
    //printf("STACK A:");
	//print_stack_variant(a);
    printf("STACK B:");
	print_stack(b);

	free_stack(&b);

	return (0);
}*/

/*
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = last_node;
	last_node->next->next = NULL;
}*/


// cc -Wall -Wextra -Werror command_rotate.c ../build_stack/*.c ../parsing/*.c ../libft/libft.a -I../libft -I../build_stack -I../parsing -I.. -o test_rotate

