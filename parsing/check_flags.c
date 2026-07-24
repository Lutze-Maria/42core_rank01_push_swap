/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 09:56:35 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/24 10:59:19 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_flag	check_flag(char *flag)
{
	if (!flag)
		return (FLAG_INVALID);
	if (ft_strncmp(flag, "--simple", 9) == 0)
		return (FLAG_SIMPLE);
	if (ft_strncmp(flag, "--medium", 9) == 0)
		return (FLAG_MEDIUM);
	if (ft_strncmp(flag, "--complex", 10) == 0)
		return (FLAG_COMPLEX);
	if (ft_strncmp(flag, "--adaptive", 11) == 0)
		return (FLAG_ADAPTIVE);
	return (FLAG_INVALID);
}

t_bench	check_bench(char *bench)
{
	if (!bench)
		return (NO_FLAG_BENCH);
	if (ft_strncmp(bench, "--bench", 8) == 0)
		return (FLAG_BENCH);
	return (NO_FLAG_BENCH);
}
