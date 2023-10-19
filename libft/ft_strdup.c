/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:45:10 by rluiz             #+#    #+#             */
/*   Updated: 2023/09/18 18:52:46 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(t_arena *arena, const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	dup = (char *)ft_calloc(arena, len + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len);
	return (dup);
}
