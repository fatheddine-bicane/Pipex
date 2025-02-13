/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:20:13 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/12 20:23:19 by fbicane          ###   ########.fr       */
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
char	*ft_here_doc(char *limiter);
char	*ft_creat_input(char *limiter);
void	ft_free(char **arr_s);
void	ft_trow_error_2(int error, char **path, char *argv);
void	ft_trow_error_3(int error, char **arr);
void	ft_check_envp_path(char **envp);
void	ft_with_here_doc(int argc, char **argv, char **envp);
void	ft_no_here_doc(int argc, char **argv, char **envp);

#endif
