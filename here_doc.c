/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:03:29 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/10 14:22:09 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strnstr_custm(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (haystack == NULL && len == 0)
			return (0);
	i = 0;
	if (needle[0] == 0)
			return (0);
	while (haystack[i] != 0 && i < len)
	{
		j = 0;
		if (haystack[i + j] == needle[j] && (i + j) < len)
		{
			while ((needle[j] != 0 && (i + j) < len)
				&& (haystack[i + j] == needle[j])
				&& (haystack[i + j] != 0))
				j++;
		}
		if (needle[j] == 0)
				return (i);
		i++;
	}
	return (0);
}


char	*ft_here_doc(char *limiter)
{
	char	*str;
	char	*join;
	char	*join_m;
	char	*stop;
	char	*tmp;

	join = ft_strdup("");
	str = get_next_line(0);
	while (!ft_strnstr(str, limiter, ft_strlen(str)))
	{
		join_m = join;
		join = ft_strjoin(join, str);
		free(join_m);
		free(str);
		str = get_next_line(0);
	}
	get_next_line(-1);
	join_m = join;
	join = ft_strjoin(join, str);
	free(join_m);
	free(str);
	stop = ft_strnstr(join, limiter, ft_strlen(join));
	int	i = ft_strnstr_custm(join, limiter, ft_strlen(join));
	int	j = 0;
	tmp = ft_calloc(i + 1, sizeof(char));
	while (j < i)
	{
		tmp[j] = join[j];
		j++;
	}
	/*tmp[j] = '\0';*/
	free(join);
	/*join = ft_strdup(tmp);*/
	return (tmp);
}
int	main(int argc, char **argv)
{
	char *str = ft_here_doc(argv[1]);
	printf("%s", str);
	free(str);
}
