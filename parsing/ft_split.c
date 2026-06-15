
#include "push_swap.h"

static char	*ft_extract_word(const char *s, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free_all(char **result, int index)
{
	while (index >= 0)
	{
		free(result[index]);
		index--;
	}
	free(result);
	return (NULL);
}

static char	**ft_fill_result(char **result, char const *s, char c)
{
	int	i;
	int	index;
	int	word_len;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			word_len = 0;
			while (s[i + word_len] && s[i + word_len] != c)
				word_len++;
			result[index] = ft_extract_word(&s[i], word_len);
			if (!result[index])
				return (ft_free_all(result, index - 1));
			index++;
			i += word_len;
		}
	}
	result[index] = NULL;
	return (result);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (words == 0)
	{
		result[0] = NULL;
		return (result);
	}
	ft_fill_result(result, s, c);
	return (result);
}
