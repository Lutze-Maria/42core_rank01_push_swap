/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket-sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 10:30:32 by dpetutsc          #+#    #+#             */
/*   Updated: 2026/07/23 10:30:29 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdint.h>

static int	sqrt(int n)
{
	int	sqroot;

	sqroot = 1;
	while (sqroot * sqroot <= n)
		sqroot++;
	return (sqroot);
}

static void	sort_into_buckets(t_stack_node **a, t_stack_node **b,
		int bucket_size, t_container *container)
{
	int		bucket;
	int		i;
	bool	checker;

	checker = false;
	i = 0;
	bucket = 1;
	while (*a)
	{
		if ((*a)->index < bucket_size * bucket)
		{
			pb(b, a, checker, container);
			i++;
		}
		else
			ra(a, checker, container);
		if (i == bucket_size)
		{
			bucket++;
			i = 0;
		}
	}
}

static void	move_to_target(t_stack_node **b, int target_distance, bool checker,
		t_container *container)
{
	if (target_distance == INT_MIN)
		return ((void)write(2, "Error: Couldnt find index\n", 26));
	while (target_distance > 0)
	{
		rb(b, checker, container);
		target_distance--;
	}
	while (target_distance < 0)
	{
		rrb(b, checker, container);
		target_distance++;
	}
}

static void	sort_buckets(t_stack_node **a, t_stack_node **b, int bucket_size,
		t_container *container)
{
	int		index;
	bool	checker;

	checker = true;
	index = stack_len(*b) - 1;
	while (*b)
	{
		if ((*b)->index == index)
		{
			pa(a, b, checker, container);
			index--;
		}
		else
		{
			move_to_target(b, get_distance_from_index(*b, index, bucket_size),
				checker, container);
		}
	}
}

void	bucket_sort(t_stack_node **a, t_container *container)
{
	t_stack_node	*b;
	int				bucket_size;

	b = NULL;
	bucket_size = sqrt(stack_len(*a));
	sort_into_buckets(a, &b, bucket_size, container);
	sort_buckets(a, &b, bucket_size, container);
}
