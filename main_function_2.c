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

void	ft_pipex(char *argv, char **envp)
{
	int		pid;
	char	**path;
	int		fds[2];

	pipe(fds);
	pid = fork();
	if (!pid)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		path = find_path(argv, envp);
		/*printf("%s", path[0]);*/
		execve(path[0], path, envp);
	}
	else
	{
		wait(NULL);
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		inf;
	int		ouf;
	char	*buff;
	int		i;
	char	**path;

	//changing the inpute from 0 to infile;
	inf = open(argv[1], O_RDONLY);
	dup2(inf, STDIN_FILENO);
	close(inf);
	//call a function (pipex)
	i = 1;
	while (++i < argc - 2)
		ft_pipex(argv[i], envp);//here i have to give the commanf for examle (argv[2])
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
	dup2(STDOUT_FILENO, ouf);
	path = find_path(argv[i], envp);
	execve(path[0], path, envp);
	/*buff = get_next_line(fds[0], '\n');*/
	/*dup2(ouf, 1);*/
	/*close(ouf);*/
	/*printf("%s", buff);*/
	/*write(ouf, &buff, 8);*/
	/*dup2(fds[1], 1);*/
	/*close(fds[1]);*/
	/*dup2(ouf, 1);*/
	/*close(ouf);*/
	//wee need to loop the amount of command -1 for example if i have 4 command i need to loop 4-1
	  //the -1 is so that the last time we wont redirect the output to be the input insted the outfile as the final rsult.
}
