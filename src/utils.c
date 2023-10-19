/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:00:33 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 15:36:17 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_handler(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	exit(0);
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
		exit(0);
	return (ret);
}

char	*my_getenv(t_arena *arena, char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(arena, env[i], 0, j);
		if (ft_strncmp(sub, name, ft_strlen(name)) == 0)
			return (env[i] + j + 1);
		i++;
	}
	return (NULL);
}

char	*get_path(t_arena *arena, char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(arena, my_getenv(arena, "PATH", env), ':');
	s_cmd = ft_split(arena, cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(arena, allpath[i], "/");
		exec = ft_strjoin(arena, path_part, s_cmd[0]);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
	}
	return (cmd);
}
