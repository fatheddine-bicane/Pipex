/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:26:26 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/12 21:11:11 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_no_here_doc(int argc, char **argv, char **envp)
{
	int		inf;
	int		ouf;
	int		i;
	char	**path;

	if (argc < 5)
		ft_trow_error_2(8, NULL, NULL);
	ft_open(argv[1], &inf);
	i = 1;
	while (++i < argc -2)
		ft_pipex(argv[i], envp);
	ouf = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ouf == -1)
		ft_trow_error(5, NULL);
	if (dup2(ouf, STDOUT_FILENO) == -1)
		ft_trow_error(5, NULL);
	close (ouf);
	path = find_path(argv[i], envp);
	if (!path)
		ft_trow_error_2(7, path, argv[i]);
	if (!*path)
		ft_trow_error_2(7, path, argv[i]);
	execve(path[0], path, envp);
	ft_free(path);
	exit(1);
}

void	ft_open_2(int *inf)
{
	(*inf) = open("tmp", O_RDONLY);
	if (dup2((*inf), STDIN_FILENO) == -1)
		ft_trow_error(5, NULL);
	close((*inf));
	unlink("tmp");
}

void	ft_helper(int argc, char *argv)
{
	char	*input;
	int		inf;

	if (argc < 6)
		ft_trow_error_2(6, NULL, NULL);
	input = ft_creat_input(argv);
	inf = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (inf == -1)
		ft_trow_error(5, NULL);
	ft_putstr_fd(input, inf);
	free(input);
	close(inf);
	ft_open_2(&inf);
	close(inf);
}

void	ft_with_here_doc(int argc, char **argv, char **envp)
{
	int		i;
	int		ouf;
	char	**path;

	if (argc < 6)
		ft_trow_error_2(6, NULL, NULL);
	ft_helper(argc, argv[2]);
	i = 2;
	while (++i < argc - 2)
		ft_pipex(argv[i], envp);
	ouf = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ouf == -1)
		ft_trow_error(5, NULL);
	if (dup2(ouf, STDOUT_FILENO) == -1)
		ft_trow_error(5, NULL);
	close (ouf);
	path = find_path(argv[i], envp);
	if (!path)
		ft_trow_error_2(7, path, argv[i]);
	if (!*path)
		ft_trow_error_2(7, path, argv[i]);
	execve(path[0], path, envp);
	ft_free(path);
}
