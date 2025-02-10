/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:44:43 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/07 20:45:53 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_trow_error(int error, char *argv)
{
	if (error == 1)
		ft_perror("khassk akhouya 5 dyal arguments\n");
	else if (error == 2)
	{
		ft_perror("La akhouya had l command: '");
		ft_perror(argv);
		ft_perror("' ma kaynach\n");
	}
	else if (error == 3)
	{
		ft_perror("ma 3dkch lh9 truni had l3iba: '");
		ft_perror(argv);
		ft_perror("' a khouya\n");
	}
	else if (error == 4)
	{
		ft_perror("khouya achno had l3iba: '");
		ft_perror(argv);
		ft_perror("' ??\n");
	}
	else if (error == 5)
		ft_perror("chi system call ma khdamach a sahbi\n");
	if (error == 6)
		ft_perror("khassk akhouya 3al a9al 5 dyal arguments\n");
	exit(1);
}
