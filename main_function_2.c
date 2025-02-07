/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:38:51 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/06 15:43:48 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(char *argv, char **envp)
{
	int		pid;
	char	**path;
	int		fds[2];

	pipe(fds);
	pid = fork();
	if (!pid)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		path = find_path(argv, envp);
		execve(path[0], path, envp);
	}
	else
	{
		wait(NULL);
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		inf;
	int		ouf;
	int		i;
	char	**path;

	inf = open(argv[1], O_RDONLY);
	dup2(inf, STDIN_FILENO);
	close(inf);
	i = 1;
	while (++i < argc - 2)
		ft_pipex(argv[i], envp);
	ouf = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(ouf, STDOUT_FILENO);
	path = find_path(argv[i], envp);
	execve(path[0], path, envp);
}
