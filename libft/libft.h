/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:15:36 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 16:05:02 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <ctype.h>
# include <limits.h>
# include <math.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_arena
{
	void			*buf;
	size_t			buf_size;
	size_t			prev_offset;
	size_t			curr_offset;
}					t_arena;

void				*arena_init(size_t buffer_size);
void				arena_reset(t_arena *a);
void				*arena_alloc(t_arena *a, size_t size);
void				arena_destroy(t_arena *a);
int					ft_isalpha(const int c);
int					ft_isdigit(const int c);
int					ft_isalnum(const int c);
int					ft_isascii(const int c);
int					ft_isprint(const int c);
int					ft_strlen(const char *s);
void				*ft_memset(void *b, const int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
int					ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_toupper(const int c);
char				*get_next_line(int fd);
int					ft_tolower(const int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, int n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
long				ft_atoi(t_arena *arena, const char *str);
void				*ft_calloc(t_arena *arena, size_t count, size_t size);
char				*ft_strdup(t_arena *arena, const char *s);
char				*ft_substr(t_arena *arena, char const *s,
						unsigned int start, size_t len);
char				*ft_strjoin(t_arena *arena, char const *s1, char const *s2);
char				*ft_strtrim(t_arena *arena, char const *s1,
						char const *set);
char				**ft_split(t_arena *arena, char const *s, char c);
char				*ft_itoa(t_arena *arena, int n);
char				*ft_strmapi(t_arena *arena, char const *s,
						char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstnew(t_arena *arena, void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_arena *arena, t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstfirst(t_list *lst);

#endif
