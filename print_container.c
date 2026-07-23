/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_container.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:58:37 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/23 11:13:26 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_container	init_container(float disorder)
{
	int	disorder_formatted;
	
	disorder_formatted = (int)(disorder * 10000);
	t_container	c = {
		.flag = FLAG_ADAPTIVE,
		.disorder = disorder_formatted,
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
	ft_printf("[bench] disorder: %d.%d%%\n", (container.disorder / 100), (container.disorder % 100));
	ft_printf("[bench] strategy: %s\n", flag_strategy);
	ft_printf("[bench] total ops: %u\n", total_ops);
	ft_printf("[bench] sa: %u, sb: %u, ss: %u, pa: %u, pb: %u,\n", 
		container.sa, container.sb, container.ss, container.pa, container.pb);
	ft_printf("[bench] ra: %u, rb: %u, rr: %u, rra: %u, rrb: %u, rrr: %u\n", 
		container.ra, container.rb, container.rr, container.rra, container.rrb, container.rrr);
}
