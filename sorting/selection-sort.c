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

static void	move_to_target(t_stack_node *stack, int target_distance,
		bool checker, t_container *container)
{
	if (target_distance == INT_MIN)
		return ((void)write(2, "Error: Couldnt find index\n", 26));
	while (target_distance > 0)
	{
		rb(&stack, checker, container);
		target_distance--;
	}
	while (target_distance < 0)
	{
		rrb(&stack, checker, container);
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
			move_to_target(*a, get_distance_from_index(*a, index, (index + 1)
					/ 2), true, container);
		}
		while (b)
			pa(a, &b, true, container);
	}
}
