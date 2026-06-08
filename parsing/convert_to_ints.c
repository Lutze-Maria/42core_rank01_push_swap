/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_ints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:41:51 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/08 17:00:40 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Converting string representation into actual int
char **tokens -> int *numbers
 */

long	*to_long_array(char **tokens, int size)
{
	
}

int	*to_int_array(char **tokens, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = ft_atoi(tokens[i]);
		i++;
	}
	return (arr);
}
