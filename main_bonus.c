/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:49:19 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/10 21:31:17 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_no_here_doc(int argc, char **argv, char **envp)
{
	int		inf;
	int		ouf;
	int		i;
	char	**path;

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
		ft_trow_error(2, argv[i]);
	execve(path[0], path, envp);
}


void	ft_open_2(int *inf)
{
	if (dup2((*inf), STDIN_FILENO) == -1)
		ft_trow_error(5, NULL);
	close((*inf));
}

void	ft_with_here_doc(int argc, char **argv, char **envp)
{
	int		inf;
	int		ouf;
	char	*input;
	int		i;
	char	**path;

	input = ft_here_doc(argv[2]);
	inf = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd(input, inf);
	free(input);
	ft_open_2(&inf);
	/*if (dup2(inf, STDIN_FILENO) == -1)*/
	/*	ft_trow_error(5, NULL);*/
	close(inf);
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
			ft_trow_error(2, argv[i]);
	execve(path[0], path, envp);
}

int	main(int argc, char **argv, char **envp)
{
	/*int		inf;*/
	/*int		ouf;*/
	/*int		i;*/
	/*char	**path;*/

	if (argc < 5)
		ft_trow_error(6, NULL);
	if (!(ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]))))
		ft_with_here_doc(argc, argv, envp);
	else
		ft_no_here_doc(argc, argv, envp);
	//the function that will do here_doc
	/*ft_open(argv[1], &inf);*/
	/*i = 1;*/
	/*while (++i < argc - 2)*/
	/*	ft_pipex(argv[i], envp);*/
	/*ouf = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);*/
	/*if (ouf == -1)*/
	/*	ft_trow_error(5, NULL);*/
	/*if (dup2(ouf, STDOUT_FILENO) == -1)*/
	/*	ft_trow_error(5, NULL);*/
	/*close (ouf);*/
	/*path = find_path(argv[i], envp);*/
	/*if (!path)*/
	/*	ft_trow_error(2, argv[i]);*/
	/*execve(path[0], path, envp);*/
}
