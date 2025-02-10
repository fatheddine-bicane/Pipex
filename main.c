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

int	main(int argc, char **argv, char **envp)
{
	int		inf;
	int		ouf;
	char	**path;

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
	path = find_path(argv[3], envp);
	if (!path)
		ft_trow_error(2, argv[3]);
	execve(path[0], path, envp);
}
