
#include "../push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("value=%d | index=%d | prev=%p | next=%p\n", stack->value,
			stack->index, stack->prev, stack->next);
		stack = stack->next;
	}
	printf("-------------------\n\n");
}

void	print_stack_variant(t_stack_node *stack)
{
	int	i;

	i = 0;
	printf("\n----- STACK -----\n");
	while (stack)
	{
		printf("[%d] value=%d | index=%d\n", i, stack->value, stack->index);
		stack = stack->next;
		i++;
	}
	printf("-------------------\n\n");
}

/*
int	main(void)
{
	char			*tokens[] = {
		"3",
		"42",
		"+42",
		NULL
	};
	t_stack_node	*a;

	a = NULL;
	stack_init(&a, tokens);
	print_stack_variant(a);

	return (0);
}*/

// cc -Wall -Wextra
//	-Werror test_stack.c stack_init.c stack_utils.c stack_error_checks.c stack_free.c ../libft/libft.a
// -I../libft -I.. -o test_stack
