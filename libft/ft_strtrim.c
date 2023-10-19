/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:09:19 by rluiz             #+#    #+#             */
/*   Updated: 2023/08/07 15:46:37 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(t_arena *arena, char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	end = 0;
	while (s1[end])
		end++;
	while (end > start && ft_in_set(s1[end - 1], set))
		end--;
	trimmed = (char *)arena_alloc(arena, (end - start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed[i++] = s1[start++];
	}
	trimmed[i] = '\0';
	return (trimmed);
}
