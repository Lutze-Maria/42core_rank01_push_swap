/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:44:17 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/21 10:37:15 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	int	i;
	int	counter;
	long	number;

	i = 0;
	counter = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			counter = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10;
		number = number + str[i] - '0';
		i++;
	}
	return (counter * number);
}

/* 
	Create stack a with the command line values (stored in num_array)
	checks included:
		duplicated values
		over/underflow
		syntax errors
 */

void	stack_init(t_stack_node **a, char **num_array)
{
	long	nbr;
	int		i;

	i = 0;
	while (num_array[i])
	{
		if (!error_syntax(num_array[i]))
		{
			printf("Error: Wrong Syntax\n");
			free_stack(a);
			//error_free(a, num_array);
			return ;
		}
		nbr = ft_atol(num_array[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			printf("Error: Overflow\n");
			free_stack(a);
			//	error_free(a, num_array);
			return ;
		}
		if (error_duplicate(*a, (int)nbr))
		{
			printf("Error: Duplicate\n");
			free_stack(a);
			//	error_free(a, num_array);
			return ;
		}
		append_node(a, (int)nbr);
		i++;
	}
}
