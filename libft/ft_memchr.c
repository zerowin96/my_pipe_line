/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:46:16 by yeham             #+#    #+#             */
/*   Updated: 2022/07/12 21:20:47 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dest, int ch, size_t size)
{
	unsigned char	*dst;

	dst = (unsigned char *)dest;
	while (size--)
	{
		if (*dst == (unsigned char)ch)
			return (dst);
		dst++;
	}
	return (0);
}
