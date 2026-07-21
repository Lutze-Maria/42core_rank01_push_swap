/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:18:23 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/21 13:20:05 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static char	**ft_free_all(char **result, int index)
// {
// 	while (index >= 0)
// 	{
// 		free(result[index]);
// 		index--;
// 	}
// 	free(result);
// 	return (NULL);
// }


static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*fill_word(char const **s, char c)
{
	char	*word;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[i] = '\0';
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words + 1)
		result[i++] = NULL;
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = fill_word(&s, c);
			if (!result[i])
			{
				free_num_array(result);
				return (NULL);
			}
			i++;
		}
	}
	return (result);
}

/*
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int	main(void)
{
	char	*s = "zero one two three four";
	char	**split_string;
	int		i;

	split_string = ft_split(s, ' ');
	if (!split_string)
	{
		free_num_array(split_string);
		return (1);
	}
	i = 0;
	while (split_string[i])
	{
		printf("%s\n", split_string[i]);
		i++;
	}
	free_num_array(split_string);
	return (0);
}*/

// cc -Wall -Wextra -Werror ft_split.c -I.. -o test_split