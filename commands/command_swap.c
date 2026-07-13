
#include "../push_swap.h"

// swap first two nodes of one stack

static void	swap(t_stack_node **head)
{
	if (NULL == *head || NULL == head)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
/*
int	main(int argc, char **argv)
{
	// initialize stack a & b, point to NULL
	t_stack_node	*a;
	//t_stack_node	*b;
	t_config 		cfg;
	char			**tokens;
	bool            silent;

	a = NULL;
	//b = NULL;
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
	//stack_init(&b, tokens);
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
	//printf("STACK B:");
	//print_stack_variant(b);

	// RUN COMMAND
	sa(&a, silent);

	printf("AFTER Command:\n\n");
	printf("STACK A:");
	print_stack_variant(a);
	//printf("STACK B:");
	//print_stack_variant(b);

	free_stack(&a);
	//free_stack(&b);
	return (0);
}*/

// cc -Wall -Wextra
//	-Werror command_swap.c ../build_stack/*.c ../parsing/*.c ../libft/libft.a
//-I../libft -I../build_stack -I../parsing -I.. -o test_swap
