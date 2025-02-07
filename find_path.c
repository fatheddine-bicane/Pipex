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
	int	i;
	int	j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(arr2) + ft_strlen(command) + 2);
	while(arr2[i])
		str[j++] = arr2[i++];
	i = 0;
	str[j++] = '/';
	while (command[i])
		str[j++] = command[i++];
	str[j] = '\0';
	return (str);
}

char	**find_path(char *argv, char **envp)
{
	char	*str;
	char	*path;
	char	**arr;
	char	**arr2;
	int		i;

	i = 0;
	arr = ft_split(argv, 32);
	str = arr[0];
	while(envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	arr2 = ft_split(envp[i] + 5, ':');
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
	return (NULL);
}
