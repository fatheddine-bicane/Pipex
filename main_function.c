/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fatheddine04@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:27:26 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 18:45:41 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int	pid;
	int	fds[2];
	int	inf;
	int	ouf;
	char str[100];
	char str2[100];
	char **str3;

	pipe(fds);
	pid = fork();
	if (pid == 0)
	{
		close(fds[0]);
		inf = open(argv[1],O_RDONLY);
		dup2(inf, 0);
		dup2(fds[1], 1);
		close(inf);
		close(fds[1]);
		//str = findpath(argv[2], envp);
		/*execve(str3[0], str3, envp);*/
		read(0, str, 40);
		write(1, &str, 40);
		exit(1);
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	pid = fork();
	if (pid == 0)
	{
		close(fds[1]);
		ouf = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(ouf, 1);
		dup2(fds[0], 0);
		ouf = open(argv[2], O_WRONLY);
		close(ouf);
		close(fds[0]);
		read(0, str2, 40);
		write(1, str2, 40);
		exit(1);
	}
	else
		waitpid(pid, NULL, 0);
	printf("copying is done");
	
}
