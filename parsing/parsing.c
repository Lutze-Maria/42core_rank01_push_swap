/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:21:33 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/08 17:23:33 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	*parse_input(int argc, char **argv, char is_bench, int *size)
{
	char	**tokens;
	int		size;

	tokens = collect_input(argc, argv, is_bench);
	if (!tokens)
		return (error());
	if (!validate_tokens(tokens))
		return (free_array(tokens), error());
	size = count_tokens(tokens);
	numbers = convert_to_ints(tokens, size);
	free_array(tokens);
	if (!numbers)
		return (error());
	if (!duplicate_check(numbers, size))
		return (free(numbers), error());
	return (numbers);
}
