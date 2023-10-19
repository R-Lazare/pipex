/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:23:04 by rluiz             #+#    #+#             */
/*   Updated: 2023/09/06 18:12:06 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(t_arena *arena, char const *s, char (*f)(unsigned int,
			char))
{
	char			*new_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	new_str = (char *)arena_alloc(arena, sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
