/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:49:19 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/10 11:22:18 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		inf;
	int		ouf;
	int		i;
	char	**path;

	if (argc < 5)
		ft_trow_error(6, NULL);
	ft_open(argv[1], &inf);
	i = 1;
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
