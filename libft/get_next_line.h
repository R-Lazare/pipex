/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:21:05 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 16:11:55 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strchr2(const char *string, int searchedChar);

void	ft_bzero2(void *s, size_t n);
void	*ft_calloc2(size_t elementCount, size_t elementSize);

size_t	ft_strlen2(const char *theString);

#endif
