/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:16:07 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/12 20:16:10 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **arr_s)
{
	int	i;

	i = 0;
	if (!arr_s)
		return ;
	while (arr_s[i] != 0)
	{
		free(arr_s[i]);
		i++;
	}
	free (arr_s);
}

void	ft_pipex_utils(int *fds, char *argv, char **envp)
{
	char	**path;

	close((fds[0]));
	if (dup2((fds[1]), STDOUT_FILENO) == -1)
		ft_trow_error(5, NULL);
	close((fds[1]));
	path = find_path(argv, envp);
	if (!path)
		ft_trow_error_2(7, path, argv);
	if (!*path)
		ft_trow_error_2(7, path, argv);
	execve(path[0], path, envp);
	ft_free(path);
	exit(1);
}

void	ft_pipex(char *argv, char **envp)
{
	int		pid;
	int		fds[2];

	if (!argv || !*argv)
		ft_trow_error_2(9, NULL, argv);
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
