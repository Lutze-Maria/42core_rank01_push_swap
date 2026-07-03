
#include "push_swap.h"

// Push a node to the top from src to dest
//ATTENTION: if stack empty (i.e. NULL)

static void push(t_stack_node **dest, t_stack_node **src)
{
    t_stack_node    *node_to_push;

    if (*src == NULL)
        return ;
    node_to_push = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    node_to_push->prev = NULL;
    if (NULL == *dest)
    {
        *dest = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *dest;
        node_to_push->next->prev = node_to_push;
        *dest = node_to_push;
    }
}

void    pa(t_stack_node **a, t_stack_node **b, bool checker)
{
    push(a, b);
    if (!checker)
        write(1, "pa\n", 3);
}

void    pb(t_stack_node **b, t_stack_node **a, bool checker)
{
    push(b, a);
    if (!checker)
        write(1, "pb\n", 3);
}

/*
int	main(int argc, char **argv)
{
	// initialize stack a & b, point to NULL
	t_stack_node	*a;
    t_stack_node	*b;
	t_config 		cfg;
	char			**tokens;
    bool            silent;

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
    pb(&b, &a, silent);

    printf("AFTER Command:\n\n");
    printf("STACK A:");
	print_stack_variant(a);
    printf("STACK B:");
	print_stack_variant(b);

	free_stack(&a);
    free_stack(&b);
	return (0);
}
*/
// cc -Wall -Wextra -Werror command_push.c ../build_stack/*.c ../parsing/*.c ../libft/libft.a -I../libft -I../build_stack -I../parsing -I.. -o test_push
