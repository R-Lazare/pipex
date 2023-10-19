/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:19:45 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 15:35:02 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_arena *arena, char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(arena, cmd, ' ');
	path = get_path(arena, s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		exit(0);
	}
}

void	child(t_arena *arena, char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(arena, av[2], env);
}

void	parent(t_arena *arena, char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec(arena, av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;
	t_arena	*arena;

	arena = arena_init(2048);
	if (ac != 5)
		exit_handler(1);
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child(arena, av, p_fd, env);
	parent(arena, av, p_fd, env);
	arena_destroy(arena);
}
