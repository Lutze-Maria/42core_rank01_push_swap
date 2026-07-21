/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetutsc <dpetutsc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:16:02 by dpetutsc          #+#    #+#             */
/*   Updated: 2026/07/21 13:16:02 by dpetutsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

int	get_distance_from_index(t_stack_node *a, int index, int max_distance)
{
	int				distance;
	int				len;
	t_stack_node	*start;

	distance = 0;
	len = stack_len(a);
	start = a;
	while (a->next && a->index != index)
	{
		a = a->next;
		distance++;
	}
	if (distance > max_distance)
	{
		distance = -1;
		a = find_last_node(start);
		while (a->prev && a->index != index)
		{
			a = a->prev;
			distance--;
		}
	}
	if (a->index != index)
		return (INT_MIN);
	return (distance);
}
