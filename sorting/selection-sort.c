/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection-sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetutsc <dpetutsc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:33:06 by dpetutsc          #+#    #+#             */
/*   Updated: 2026/07/14 10:40:27 by dpetutsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdint.h>

void	selection_sort(t_stack_node **a)
{
	int				smallest;
	t_stack_node	**b;

	b = malloc(sizeof(t_stack_node **));
	if (!b)
		return ;
	*b = NULL;
	smallest = INT_MAX;
	while (*a)
	{
		if (smallest > (*a)->value)
			smallest = (*a)->value;
		else if ((*a)->value == smallest)
		{
			pb(b, a, false);
			smallest = INT_MAX;
		}
		ra(a, false);
	}
	while (*b)
		pa(a, b, false);
	free(b);
}
