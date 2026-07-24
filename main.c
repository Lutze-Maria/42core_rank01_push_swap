/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:07:45 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/24 10:42:19 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_config		cfg;
	char			**tokens;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	cfg = parse_config(argc, argv);
	tokens = parse_input(argc, argv, cfg.start);
	if (!tokens)
		return ((void)ft_printf(2, "Error\n"), 1);
	if (stack_init(&a, tokens))
		return (free_num_array(tokens), 1);
	free_num_array(tokens);
	if (!a)
		return (1);
	assign_index(a);
	sort_stack(&a, cfg, compute_disorder(&a));
	free_stack(&a);
	return (0);
}
