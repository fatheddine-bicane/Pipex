/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:49:19 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/10 21:31:17 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	ft_check_envp_path(envp);
	if (!(ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]))))
		ft_with_here_doc(argc, argv, envp);
	else
		ft_no_here_doc(argc, argv, envp);
}
