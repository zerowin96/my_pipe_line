/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:50:28 by yeham             #+#    #+#             */
/*   Updated: 2022/07/12 21:21:14 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	const unsigned char	*pt1 = (unsigned char *)ptr1;
	const unsigned char	*pt2 = (unsigned char *)ptr2;

	while (size--)
	{
		if (*pt1 != *pt2)
			return (*pt1 - *pt2);
		pt1++;
		pt2++;
	}
	return (0);
}
