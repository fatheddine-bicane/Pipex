/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:38:51 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/07 14:24:16 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(char *argv, char **envp)
{
	int		pid;
	char	**path;
	int		fds[2];

	if (pipe(fds) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (!pid)
	{
		close (fds[0]);
		if (dup2(fds[1], STDOUT_FILENO) == -1)
			exit(1);
		close(fds[1]);
		path = find_path(argv, envp);
		execve(path[0], path, envp);
		exit(1);
	}
	else
	{
		close (fds[1]);
		wait(NULL);
		if (dup2(fds[0], STDIN_FILENO) == -1)
			exit(1);
		close(fds[0]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		inf;
	int		ouf;
	int		i;
	char	**path;

	if (!(argc == 5))
		exit(1);
	inf = open(argv[1], O_RDONLY);
	if (inf == -1)
		exit (1);
	if (dup2(inf, STDIN_FILENO) == -1)
		exit (1);
	close(inf);
	i = 1;
	while (++i < argc - 2)
		ft_pipex(argv[i], envp);
	ouf = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ouf == -1)
		exit (1);
	if (dup2(ouf, STDOUT_FILENO) == -1)
		exit (1);
	close (ouf);
	path = find_path(argv[i], envp);
	if (!path)
	{
		ft_perror("la akhouya hadchi ma khdamch");
		return (0);
	}
	execve(path[0], path, envp);
}
