/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:44:43 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/12 19:17:11 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_trow_error(int error, char *argv)
{
	if (error == 1)
		ft_perror("Error: The program requires exactly 5 arguments to run\n");
	else if (error == 2)
	{
		ft_perror("Error: Command not found: ");
		ft_perror(argv);
		ft_perror("\n");
	}
	else if (error == 3)
	{
		ft_perror("Error: You don't have permission to run this command: ");
		ft_perror(argv);
		ft_perror("\n");
	}
	else if (error == 4)
	{
		ft_perror("Error: File not found: ");
		ft_perror(argv);
		ft_perror(" , Please make sure the file exists and try again\n");
	}
	else if (error == 5)
		ft_perror("Error: System call failed. Please try again\n");
	exit(1);
}

void	ft_trow_error_2(int error, char **path, char *argv)
{
	if (error == 6)
	{
		ft_perror("Error: Insufficient arguments for heredoc option");
		ft_perror(". Minimum required: 6 arguments\n");
	}
	else if (error == 7)
	{
		ft_perror("Error: Command not found: ");
		ft_perror(argv);
		ft_perror("\n");
		ft_free(path);
	}
	else if (error == 8)
	{
		ft_perror("Error: Insufficient arguments for pipex.");
		ft_perror("Minimum required: 5 arguments\n");
	}
	else if (error == 9)
	{
		ft_perror("Error: Permission denied: ");
		ft_perror(argv);
		ft_free(path);
	}
	exit(1);
}

void	ft_trow_error_3(int error, char **arr)
{
	if (error == 10)
	{
		ft_perror("Error: Failed to access system environment");
		ft_perror("variables\n");
		ft_perror("Fix: Save your work and restart your machine\n");
	}
	else if (error == 11)
	{
		ft_perror("Error: PATH not found in system environment variables\n");
		ft_perror("Fix: Save your work and restart your machine\n");
	}
	else if (error == 12)
	{
		ft_perror("Error: Command not found: ");
		ft_perror(arr[0]);
		ft_perror("\n");
		ft_free(arr);
	}
	exit(1);
}
