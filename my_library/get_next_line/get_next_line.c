/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:26:17 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 15:26:13 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

static char	*get_the_reminder(char *container, char to_find)
{
	char	*new_container;
	char	*temp_container;

	if (!container)
		return (NULL);
	temp_container = ft_strchr(container, to_find);
	if (!temp_container)
		return (free(container), NULL);
	new_container = ft_strdup(temp_container + 1);
	free(container);
	return (new_container);
}

static char	*get_the_newline(char *container, char to_find)
{
	size_t	i;
	char	*new_line;

	if (!container)
		return (NULL);
	i = 0;
	while (container[i] && container[i] != to_find)
		i++;
	if (container[i] == to_find)
		i++;
	new_line = malloc((i + 1) * sizeof(char));
	if (!new_line)
		return (free (container), NULL);
	new_line = ft_memmove(new_line, container, i);
	new_line[i] = '\0';
	return (new_line);
}

static char	*read_from_fd(int fd, char *container, char to_find)
{
	ssize_t	bytes_read;
	char	*buffer;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (buffer), free (container), NULL);
		buffer[bytes_read] = '\0';
		container = ft_strjoin(container, buffer);
		if (ft_strchr(buffer, to_find))
			break ;
	}
	free(buffer);
	if (bytes_read == 0 && (!container || !*container))
		return (free(container), container = NULL);
	return (container);
}

char	*get_next_line(int fd, char to_find)
{
	static char	*container;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free (container), NULL);
	if (!container)
	{
		container = malloc(1 * sizeof (char));
		if (!container)
			return (NULL);
		*container = '\0';
	}
	if (!ft_strchr(container, to_find))
		container = read_from_fd(fd, container, to_find);
	if (!container)
		return (free (container), NULL);
	line = get_the_newline(container, to_find);
	container = get_the_reminder(container, to_find);
	return (line);
}
