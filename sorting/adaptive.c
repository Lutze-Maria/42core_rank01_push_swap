/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:33:18 by dpetutsc          #+#    #+#             */
/*   Updated: 2026/07/22 16:03:26 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	compute_disorder(t_stack_node **a)
{
	int				mistakes;
	int				total_pairs;
	t_stack_node	*current_node;
	t_stack_node	*first_node;

	mistakes = 0;
	total_pairs = 0;
	first_node = *a;
	while (*a)
	{
		current_node = *a;
		while ((*a)->next)
		{
			(*a) = (*a)->next;
			total_pairs++;
			if (current_node->value > (*a)->value)
				mistakes++;
		}
		*a = current_node->next;
	}
	*a = first_node;
	return ((float)mistakes / total_pairs);
}

void	sort_stack(t_stack_node **a, t_config cfg, float disorder)
{
	t_container	container;

	container = init_container(disorder);
	if (cfg.flag == FLAG_SIMPLE)
		selection_sort(a, &container);
	else if (cfg.flag == FLAG_MEDIUM)
		bucket_sort(a, &container);
	else if (cfg.flag == FLAG_COMPLEX)
		;
	else if (disorder < .2)
		selection_sort(a, &container);
	else if (disorder < .5)
		bucket_sort(a, &container);
	else
		;
	return ;
}
