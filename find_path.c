/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:16:47 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/12 20:36:46 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_concat_path(char *arr2, char *command)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(arr2) + ft_strlen(command) + 2);
	while (arr2[i])
		str[j++] = arr2[i++];
	i = 0;
	str[j++] = '/';
	while (command[i])
		str[j++] = command[i++];
	str[j] = '\0';
	return (str);
}

static char	**ft_find_path_utils_2(char **envp, char **arr, char **str)
{
	char	**arr2;
	int		i;

	if (!arr || !*arr)
		return (NULL);
	if (!access(arr[0], F_OK | X_OK))
		return (NULL);
	if (arr[0][0] == '/' || arr[0][0] == '.')
		ft_trow_error_3(12, arr);
	(*str) = arr[0];
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	arr2 = ft_split(envp[i] + 5, ':');
	return (arr2);
}

char	**find_path(char *argv, char **envp)
{
	char	*str;
	char	*path;
	char	**arr;
	char	**arr2;
	int		i;

	str = NULL;
	arr = ft_split(argv, 32);
	arr2 = ft_find_path_utils_2(envp, arr, &str);
	if (!arr2)
		return (arr);
	i = 0;
	while (arr2[i])
	{
		path = ft_concat_path(arr2[i], str);
		if (!access(path, F_OK | X_OK))
		{
			free(arr[0]);
			arr[0] = path;
			return (arr);
		}
		free(path);
		i++;
	}
	return (ft_free(arr), ft_free(arr2), NULL);
}

void	ft_check_envp_path(char **envp)
{
	int	i;

	if (!envp || !*envp)
		ft_trow_error_3(10, NULL);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		ft_trow_error_3(11, NULL);
}
