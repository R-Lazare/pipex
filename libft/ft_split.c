/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:44:12 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 15:19:20 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

static char	*get_next_word(t_arena *arena, char **s, char c)
{
	char	*start;
	char	*end;

	while (**s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	end = *s;
	return (ft_substr(arena, start, 0, end - start));
}

char	**ft_split(t_arena *arena, char const *s, char c)
{
	char	**result;
	char	*str;
	int		words_count;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)s;
	words_count = count_words(s, c);
	result = (char **)arena_alloc(arena, (words_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words_count)
	{
		result[i] = get_next_word(arena, &str, c);
		i++;
	}
	result[i] = NULL;
	return (result);
}
