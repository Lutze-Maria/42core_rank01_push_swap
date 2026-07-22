/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection-sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:33:06 by dpetutsc          #+#    #+#             */
/*   Updated: 2026/07/22 15:55:04 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdint.h>

void	selection_sort(t_stack_node **a, t_container *container)
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
			pb(b, a, false, container);
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
				ra(a, false, container);
				target_distance--;
			}
			while (target_distance < 0)
			{
				rra(a, false, container);
				target_distance++;
			}
		}
	}
	while (*b)
		pa(a, b, false, container);
	free(b);
}
