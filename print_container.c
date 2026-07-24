/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_container.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:58:37 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/24 09:52:38 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_container	init_container(float disorder, bool checker)
{
	int			disorder_formatted;
	t_container	c;

	disorder_formatted = (int)(disorder * 10000);
	c.disorder = disorder_formatted;
	c.checker = checker;
	c.flag = FLAG_ADAPTIVE;
	c.pa = 0;
	c.pb = 0;
	c.rra = 0;
	c.rrb = 0;
	c.rrr = 0;
	c.ra = 0;
	c.rb = 0;
	c.rr = 0;
	c.sa = 0;
	c.sb = 0;
	c.ss = 0;
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
		if (container.disorder < 2000)
			return ("Adaptive -> Simple / O(n^2)");
		else if (container.disorder < 5000)
			return ("Adaptive -> Medium / O(n√n)");
		else
			return ("Adaptive -> Complex / O(n log n)");
	}
	return (NULL);
}

void	print_container(t_container container, t_config config)
{
	unsigned int	total_ops;
	const char		*flag_strategy;

	flag_strategy = init_flag_strategy(container, config);
	total_ops = container.sa + container.sb + container.ss + container.pa
		+ container.pb + container.ra + container.rb + container.rr
		+ container.rra + container.rrb + container.rrr;
	ft_printf(2, "[bench] disorder: %d.%d%%\n", (container.disorder / 100),
		(container.disorder % 100));
	ft_printf(2, "[bench] strategy: %s\n", flag_strategy);
	ft_printf(2, "[bench] total ops: %u\n", total_ops);
	ft_printf(2, "[bench] sa: %u, sb: %u, ss: %u, pa: %u, pb: %u,\n",
		container.sa, container.sb, container.ss, container.pa, container.pb);
	ft_printf(2, "[bench] ra: %u, rb: %u, rr: %u, rra: %u, rrb: %u, rrr: %u\n",
		container.ra, container.rb, container.rr, container.rra, container.rrb,
		container.rrr);
}
