/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble-sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetutsc <dpetutsc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:33:06 by dpetutsc          #+#    #+#             */
/*   Updated: 2026/07/13 10:33:06 by dpetutsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdint.h>

void	selection_sort(t_stack_node **a, bool bench)
{
	t_stack_node	*smallest;
	t_stack_node	**b;

	b = malloc(sizeof(t_stack_node **));
	if (!b)
		return ;
	*b = NULL;
	(void)bench;
	while (*a)
	{
		if (!smallest || smallest->value > (*a)->value)
			smallest = *a;
		else if ((uintptr_t)*a == (uintptr_t)smallest)
		{
			pb(b, a, false);
			smallest = NULL;
		}
		ra(a, false);
	}
	while (*b)
		pa(a, b, false);
}
