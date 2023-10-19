/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:09:15 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/19 15:46:51 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	here_doc_put_in(char **av, int *p_fd)
{
	char	*ret;

	close(p_fd[0]);
	while (1)
	{
		ret = get_next_line(0);
		printf("ret = %s\n", ret);
		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0)
			exit(0);
		ft_putstr_fd(ret, p_fd[1]);
	}
}

void	here_doc(char **av)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		here_doc_put_in(av, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}

void	do_pipe(t_arena *arena, char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		exec(arena, cmd, env);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd_in;
	int	fd_out;
	t_arena	*arena;

	arena = arena_init(2048);
	if (ac < 5)
		exit_handler(1);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			exit_handler(1);
		i = 3;
		fd_out = open_file(av[ac - 1], 2);
		here_doc(av);
	}
	else
	{
		i = 2;
		fd_in = open_file(av[1], 0);
		fd_out = open_file(av[ac - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < ac - 2)
		do_pipe(arena, av[i++], env);
	dup2(fd_out, 1);
	exec(arena, av[ac - 2], env);
	arena_destroy(arena);
}
