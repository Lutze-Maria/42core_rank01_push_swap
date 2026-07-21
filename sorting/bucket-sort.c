/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket-sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetutsc <dpetutsc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 10:30:32 by dpetutsc          #+#    #+#             */
/*   Updated: 2026/07/14 10:30:32 by dpetutsc         ###   ########.fr       */
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
		int bucket_size)
{
	int	bucket;
	int	i;

	i = 0;
	bucket = 1;
	while (*a)
	{
		if ((*a)->index < bucket_size * bucket)
		{
			pb(b, a, false);
			i++;
		}
		else
			ra(a, false);
		if (i == bucket_size)
		{
			bucket++;
			i = 0;
		}
	}
}

static void	sort_buckets(t_stack_node **a, t_stack_node **b, int bucket_size)
{
	int	index;
	int	target_distance;

	index = stack_len(*b) - 1;
	while (*b)
		if ((*b)->index == index)
		{
			pa(a, b, false);
			index--;
		}
		else
		{
			target_distance = get_distance_from_index(*b, index, bucket_size);
			if (target_distance == INT_MIN)
				return (void)write(2, "Error: Couldnt find index\n", 26);
			while (target_distance > 0)
			{
				rb(b, false);
				target_distance--;
			}
			while (target_distance < 0)
			{
				rrb(b, false);
				target_distance++;
			}
		}
}

void	bucket_sort(t_stack_node **a)
{
	t_stack_node	**b;
	int				bucket_size;

	b = malloc(sizeof(t_stack_node **));
	if (!b)
		return ;
	*b = NULL;
	bucket_size = sqrt(stack_len(*a));
	sort_into_buckets(a, b, bucket_size);
	sort_buckets(a, b, bucket_size);
	free(b);
}
