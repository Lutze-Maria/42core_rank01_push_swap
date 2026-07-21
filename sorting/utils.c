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

int	get_position_from_index(t_stack_node *a, int index)
{
	int	pos;

	pos = 0;
	while (a->prev)
		a = a->prev;
	while (a->next && a->index != index)
	{
		a = a->next;
		pos++;
	}
	if (a->index != index)
		return (INT_MIN);
	return (pos);
}
