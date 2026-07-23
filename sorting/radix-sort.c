/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix-sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 10:30:32 by dpetutsc          #+#    #+#             */
/*   Updated: 2026/07/23 21:01:07 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdbool.h>
#include <stdlib.h>

static int	calculate_bits(int n)
{
	int	bits;

	bits = 0;
	while (n > 0)
	{
		n = n >> 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack_node **a, t_container *container, bool checker)
{
	t_stack_node	*b;
	int				bits;
	int				bit;
	int				len;
	int				i;

	b = NULL;
	bit = 0;
	len = stack_len(*a);
	bits = calculate_bits(len - 1);
	while (bit < bits)
	{
		i = 0;
		while (i < len)
		{
			if ((((*a)->index >> bit) & 1) == 0)
				pb(&b, a, checker, container);
			else
				ra(a, checker, container);
			i++;
		}
		while (b)
			pa(a, &b, checker, container);
		bit++;
	}
}
