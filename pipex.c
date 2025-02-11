/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:56:25 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/09 21:56:49 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_utils(int *fds, char *argv, char **envp)
{
	char	**path;

	close((fds[0]));
	if (dup2((fds[1]), STDOUT_FILENO) == -1)
		ft_trow_error(5, NULL);
	close((fds[1]));
	path = find_path(argv, envp);
	if (!path)
		ft_trow_error(2, argv);
	execve(path[0], path, envp);
	exit(1);
}

void	ft_pipex(char *argv, char **envp)
{
	int		pid;
	int		fds[2];

	if (pipe(fds) == -1)
		ft_trow_error(5, NULL);
	pid = fork();
	if (pid == -1)
		ft_trow_error(5, NULL);
	if (!pid)
		ft_pipex_utils(fds, argv, envp);
	else
	{
		close (fds[1]);
		wait(NULL);
		if (dup2(fds[0], STDIN_FILENO) == -1)
			ft_trow_error(5, NULL);
		close(fds[0]);
	}
}

void	ft_open(char *infile, int *inf)
{
	(*inf) = open(infile, O_RDONLY);
	if ((*inf) == -1)
		ft_trow_error(4, infile);
	if (dup2((*inf), STDIN_FILENO) == -1)
		ft_trow_error(5, NULL);
	close((*inf));
}

