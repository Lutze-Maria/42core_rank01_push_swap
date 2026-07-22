/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_container.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:58:37 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/22 16:15:56 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_container	init_container(float disorder)
{
	t_container	c = {
		.flag = FLAG_ADAPTIVE,
		.disorder = disorder,
	};
	return (c);
}

const char	*init_flag_strategy(t_container container, t_config config)
{
	if (config.flag == FLAG_SIMPLE)
		return ("Simple / O(n^2)");
	else if (config.flag == FLAG_MEDIUM)
		return ("Medium / O(n√n)");
	else if (config.flag == FLAG_COMPLEX)
		return ("Complex / O(n log n)");
	else if (config.flag == FLAG_ADAPTIVE)
	{
		if (container.disorder < 0.2)
			return ("Adaptive / O(n^2)");
		else if (container.disorder < 0.5)
			return ("Adaptive / O(n^2)");
		else
			return ("Adaptive / O(n log n)");
	}
	return (NULL);
}

void	print_container(t_container container, t_config config)
{
	unsigned int	total_ops;
	const char		*flag_strategy;

	flag_strategy = init_flag_strategy(container, config);
	total_ops = container.sa + container.sb + container.ss
		+ container.pa + container.pb
		+ container.ra + container.rb + container.rr
		+ container.rra + container.rrb + container.rrr;
	printf("[bench] disorder: %f\n", container.disorder);
	printf("[bench] strategy: %s\n", flag_strategy);
	printf("[bench] total ops: %u\n", total_ops);
	printf("[bench] sa: %u, sb: %u, ss: %u, pa: %u, pb: %u,\n", 
		container.sa, container.sb, container.ss, container.pa, container.pb);
	printf("[bench] ra: %u, rb: %u, rr: %u, rra: %u, rrb: %u, rrr: %u\n", 
		container.ra, container.rb, container.rr, container.rra, container.rrb, container.rrr);
}

