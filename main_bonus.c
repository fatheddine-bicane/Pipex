/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:49:19 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/07 21:30:14 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	int		file;

	line = "x";
	file = open("file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(file, 1);
	while (!ft_strnstr(line, argv[1], ft_strlen(line)))
	{
		line = get_next_line(0, '\n');
		printf("%s", line);
	}
	exit(1);
	printf("%s", line);
	//what is in the top i can read toa file from stdin
	
}
