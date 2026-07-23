/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection-sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:33:06 by dpetutsc          #+#    #+#             */
/*   Updated: 2026/07/23 10:30:51 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdint.h>

static void	move_to_target(t_stack_node **a, int target_distance, bool checker,
		t_container *container)
{
	while (target_distance > 0)
	{
		ra(a, checker, container);
		target_distance--;
	}
	while (target_distance < 0)
	{
		rra(a, checker, container);
		target_distance++;
	}
}

void	selection_sort(t_stack_node **a, t_container *container)
{
	int				index;
	t_stack_node	*b;
	int				target_distance;

	b = NULL;
	index = stack_len(*a) - 1;
	while (*a)
	{
		if ((*a)->index == index)
		{
			pb(&b, a, true, container);
			index--;
		}
		else
		{
			target_distance = get_distance_from_index(*a, index, (index + 1)
					/ 2);
			if (target_distance == INT_MIN)
				return ((void)write(2, "Error: Couldnt find index\n", 26));
			move_to_target(a, target_distance, true, container);
		}
	}
	while (b)
		pa(a, &b, true, container);
}
