/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:40:27 by yeham             #+#    #+#             */
/*   Updated: 2022/09/14 20:17:53 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;

	if (*lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		now = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = now;
	}
}
