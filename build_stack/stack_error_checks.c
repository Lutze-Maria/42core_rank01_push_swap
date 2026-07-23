/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_error_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:35:12 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/22 10:55:59 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i]) // only "+" or "-"
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	error_duplicate(t_stack_node *a, int new_nbr)
{
	while (a)
	{
		if (a->value == new_nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
