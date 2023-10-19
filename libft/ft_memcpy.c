/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:50:00 by rluiz             #+#    #+#             */
/*   Updated: 2023/09/07 17:17:10 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	size_t			i;

	d = (char *)dst;
	s = (const char *)src;
	if (!dst && !src)
		return (NULL);
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return (dst);
}
