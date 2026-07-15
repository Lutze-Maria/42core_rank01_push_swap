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

static t_stack_node	*find_first_node(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a->prev)
		a = a->prev;
	return (a);
}

static int	distance_to_element(t_stack_node **a, int index, int bucket_size)
{
	t_stack_node	*b;
	int				i;
	int				len;

	len = stack_len(*a);
	if (len <= 1)
		return (0);
	b = *a;
	i = 0;
	while (i < bucket_size)
	{
		if (b == NULL && (uintptr_t)b != (uintptr_t)find_first_node(*a))
		{
			b = find_first_node(*a);
			if (b == NULL)
				print_stack(b);
		}
		if (b->index == index)
			return (i);
		b = b->next;
		i++;
	}
	b = *a;
	i = 0;
	while (-i < bucket_size)
	{
		if (b == NULL && (uintptr_t)b != (uintptr_t)find_last_node(*a))
		{
			b = find_last_node(*a);
			if (b == NULL)
				print_stack(b);
		}
		if (b->index == index)
			return (i);
		b = b->prev;
		i--;
	}
	return (0);
}

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
		if ((*a)->index <= bucket_size * bucket)
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

static void	selection_sort_buckets(t_stack_node **a, t_stack_node **b,
		int bucket_size)
{
	int	i;
	int	distance;

	i = stack_len(*b) - 1;
	if (b)
		distance = distance_to_element(b, i, bucket_size);
	while (*b)
	{
		if ((*b)->index == i)
		{
			print_stack(*b);
			pa(a, b, false);
			i--;
			if (b)
				distance = distance_to_element(b, i, bucket_size);
		}
		else if (distance > 0)
			rb(b, false);
		else if (distance < 0)
		{
			rrb(b, false);
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
	selection_sort_buckets(a, b, bucket_size);
	free(b);
}
