/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:03:29 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/13 13:13:28 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_apend_new_line(char *str)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\n';
	i++;
	str2[i] = '\0';
	return (str2);
}

char	*ft_creat_input(char *limiter)
{
	char	*str;
	char	*join;
	char	*join_m;
	char	*limiter_n;

	join = ft_strdup("");
	limiter_n = ft_apend_new_line(limiter);
	str = get_next_line(0);
	while (str && ft_strncmp(str, limiter_n, ft_strlen(limiter_n)))
	{
		join_m = join;
		join = ft_strjoin(join, str);
		free(join_m);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	get_next_line(-1);
	free(limiter_n);
	return (join);
}
