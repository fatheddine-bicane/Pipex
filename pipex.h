/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fatheddine04@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:27:08 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 18:11:07 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./my_library/my_library.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

char	**find_path(char *argv, char **envp);
void	ft_trow_error(int error, char *argv);
void	ft_pipex_utils(int *fds, char *argv, char **envp);
void	ft_pipex(char *argv, char **envp);
void	ft_open(char *infile, int *inf);

#endif
