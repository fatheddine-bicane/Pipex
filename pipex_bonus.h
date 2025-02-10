/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:20:13 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/10 11:22:13 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
