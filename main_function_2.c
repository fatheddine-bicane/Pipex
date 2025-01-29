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

int	main(int argc, char **argv, char **envp)
{
	//changing the inpute from 0 to infile;
	//call a function (pipex)
	//pipex()
		//pipex will create a pipe first;
		//fork()
		//if (pid == 0)
			//change outpute to the pipe
			//execute;
		//else
			//waitpid(pid); => or wait (cuz u will have one child at the time)
	//change the input the inpute to the pipe dup2(fd[0], 0)
	//wee need to loop the amount of command -1 for example if i have 4 command i need to loop 4-1
	  //the -1 is so that the last time we wont redirect the output to be the input insted the outfile as the final rsult.
}
