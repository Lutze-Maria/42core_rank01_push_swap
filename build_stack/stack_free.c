/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:35:49 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/21 12:05:49 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free(t_stack_node **a, char **num_array)
{
	if (a)
		free_stack(a);
	if (num_array)
		free_num_array(num_array);
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_num_array(char **num_array)
{
	int	i;

	if (!num_array)
		return ;
	i = 0;
	while (num_array[i])
	{
		free(num_array[i]);
		i++;
	}
	free (num_array);
}
/*
void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}*/
