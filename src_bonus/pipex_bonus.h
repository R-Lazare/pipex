/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:18:27 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 15:53:53 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h" 
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	exit_handler(int n_exit);
int		open_file(char *file, int n);
char	*my_getenv(t_arena *arena, char *name, char **env);
char	*get_path(t_arena *arena, char *cmd, char **env);
void	exec(t_arena *arena, char *cmd, char **env);\

#endif