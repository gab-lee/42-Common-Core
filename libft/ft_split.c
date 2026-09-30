/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:23:43 by gabrlee           #+#    #+#             */
/*   Updated: 2026/09/28 17:29:20 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c);
static int	ft_word_len(char const *s, char c);
static char	*ft_new_word(char const *s, char c, int *index);
static char	**ft_free_array(char **array, int i);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**array;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (++i, i < words)
	{
		array[i] = ft_new_word(s, c, &j);
		if (!array[i])
			return (ft_free_array(array, i));
	}
	array[i] = NULL;
	return (array);
}

static char	**ft_free_array(char **array, int i)
{
	while (i--, i >= 0)
		free(array[i]);
	free(array);
	return (NULL);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = -1;
	count = 0;
	in_word = 0;
	while (++i, s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
	}
	return (count);
}

static char	*ft_new_word(char const *s, char c, int *index)
{
	int		i;
	char	*word;
	int		len;

	i = -1;
	while (s[*index] == c)
		(*index)++;
	len = ft_word_len(&s[*index], c);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (++i, i < len)
		word[i] = s[*index + i];
	word[i] = '\0';
	*index = *index + len;
	return (word);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = -1;
	while (len++, s[len] && s[len] != c)
		;
	return (len);
}
