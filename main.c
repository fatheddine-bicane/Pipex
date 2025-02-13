/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:16:35 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/12 20:16:37 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		inf;
	int		ouf;
	char	**path;

	ft_check_envp_path(envp);
	if (!(argc == 5))
		ft_trow_error(1, NULL);
	ft_open(argv[1], &inf);
	ft_pipex(argv[2], envp);
	ouf = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ouf == -1)
		ft_trow_error(5, NULL);
	if (dup2(ouf, STDOUT_FILENO) == -1)
		ft_trow_error(5, NULL);
	close (ouf);
	if (!argv || !*argv)
		ft_trow_error_2(9, NULL, argv[3]);
	path = find_path(argv[3], envp);
	if (!path)
		ft_trow_error_2(7, path, argv[3]);
	if (!*path)
		ft_trow_error_2(7, path, argv[3]);
	execve(path[0], path, envp);
	ft_free(path);
}
