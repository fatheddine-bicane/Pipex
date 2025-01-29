/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:22:42 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 15:30:52 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

void	ft_lstadd_front(t_list **lst, t_list *new_)
{
	if (!new_ || !lst)
		return ;
	new_->next = *lst;
	*lst = new_;
}
