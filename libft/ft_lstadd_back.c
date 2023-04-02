/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:06:04 by yeham             #+#    #+#             */
/*   Updated: 2022/07/26 10:26:09 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*now;

	now = *lst;
	if (lst == 0 || new == 0)
		return ;
	else if (*lst == 0 && new != 0)
	{
		*lst = new;
		return ;
	}
	while (now->next)
	{
		now = now->next;
	}
	now->next = new;
}
