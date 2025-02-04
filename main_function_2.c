/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fatheddine04@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:38:51 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 20:02:21 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_pipex(char *argv, char **envp, int *fds)
{
	int		pid;
	char	**path;

	pipe(fds);
	pid = fork();
	if (!pid)
	{
		dup2(fds[1], 1);
		close(fds[1]);
		path = find_path(argv, envp);
		/*printf("%s", path[0]);*/
		execve(path[0], path, envp);
	}
	else
		wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		inf;
	int		ouf;
	int		fds[2];
	char	*buff;

	//changing the inpute from 0 to infile;
	inf = open(argv[1], O_RDONLY);
	dup2(inf, 0);
	close(inf);
	//call a function (pipex)
	ft_pipex(argv[2], envp, fds);//here i have to give the commanf for examle (argv[2])
	//pipex()
	//pipex will create a pipe first;
		//fork()
		//if (pid == 0)
			//change outpute to the pipe
			//execute;
		//else
			//waitpid(pid); => or wait (cuz u will have one child at the time)
	//change the input the inpute to the pipe dup2(fd[0], 0)
	ouf = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	read(fds[0], buff, 8);
	buff = get_next_line(fds[0], '\n');
	write(ouf, &buff, 8);
	/*dup2(fds[1], 1);*/
	/*close(fds[1]);*/
	/*dup2(ouf, 1);*/
	/*close(ouf);*/
	//wee need to loop the amount of command -1 for example if i have 4 command i need to loop 4-1
	  //the -1 is so that the last time we wont redirect the output to be the input insted the outfile as the final rsult.
}
