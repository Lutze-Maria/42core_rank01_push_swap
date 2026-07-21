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
	int				index;
	int				target_distance;
	t_stack_node	**b;

	b = malloc(sizeof(t_stack_node **));
	if (!b)
		return ;
	*b = NULL;
	index = stack_len(*a) - 1;
	while (*a)
	{
		if ((*a)->index == index)
		{
			pb(b, a, false);
			index--;
		}
		else
		{
			target_distance = get_distance_from_index(*a, index, (index + 1)
					/ 2);
			if (target_distance == INT_MIN)
				return (void)write(2, "Error: Couldnt find index\n", 26);
			while (target_distance > 0)
			{
				ra(a, false);
				target_distance--;
			}
			while (target_distance < 0)
			{
				rra(a, false);
				target_distance++;
			}
		}
	}
	while (*b)
		pa(a, b, false);
	free(b);
}
