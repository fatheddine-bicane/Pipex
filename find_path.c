/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fatheddine04@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:08:57 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 18:42:07 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_concat_path(char *arr2, char *command)
{
	int		i;
	int		j;
	char	*str;

	if (!arr2 || !command)
		return (NULL);
	str = malloc(ft_strlen(arr2) + ft_strlen(command) + 2);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (arr2[i])
		str[j++] = arr2[i++];
	str[j++] = '/';
	i = 0;
	while (command[i])
		str[j++] = command[i++];
	str[j] = '\0';
	return (str);
}

static void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**ft_path_finder(char **arr, char **envp)
{
	char	**arr2;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	arr2 = ft_split(envp[i] + 5, ':');
	if (!arr2)
		return (free_arr(arr), NULL);
	return (arr2);
}

char	**ft_command_finder(char **arr2, char *str, char **arr)
{
	char	*path;
	int		i;

	i = 0;
	while (arr2[i])
	{
		path = ft_concat_path(arr2[i], str);
		if (!path)
			return (free_arr(arr), free_arr(arr2), NULL);
		if (!access(path, F_OK | X_OK))
		{
			free(arr[0]);
			arr[0] = path;
			free_arr(arr2);
			return (arr);
		}
		free(path);
		i++;
	}
	return (free_arr(arr), free_arr(arr2), NULL);
}

char	**find_path(char *argv, char **envp)
{
	char	*str;
	char	**arr;
	char	**arr2;

	if (!argv || !envp)
		return (NULL);
	arr = ft_split(argv, 32);
	if (!arr)
		return (NULL);
	str = arr[0];
	if (!str)
		return (free_arr(arr), NULL);
	arr2 = ft_path_finder(arr, envp);
	if (!arr2)
		return (free_arr(arr), NULL);
	return (ft_command_finder(arr2, str, arr));
}
