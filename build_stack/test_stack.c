/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:40:04 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/24 09:52:18 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		ft_printf(1, "value=%d | index=%d | prev=%p | next=%p\n", stack->value,
			stack->index, stack->prev, stack->next);
		stack = stack->next;
	}
	ft_printf(1, "-------------------\n\n");
}

void	print_stack_variant(t_stack_node *stack)
{
	int	i;

	i = 0;
	ft_printf(1, "\n----- STACK -----\n");
	while (stack)
	{
		ft_printf(1, "[%d] value=%d | index=%d\n",
			i, stack->value, stack->index);
		stack = stack->next;
		i++;
	}
	ft_printf(1, "-------------------\n\n");
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
//	-Werror test_stack.c stack_init.c
// stack_utils.c stack_error_checks.c stack_free.c ../libft/libft.a
// -I../libft -I.. -o test_stack
