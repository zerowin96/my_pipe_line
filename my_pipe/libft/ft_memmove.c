/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:11:45 by yeham             #+#    #+#             */
/*   Updated: 2022/07/12 22:07:15 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*sc = (const unsigned char *)src;

	i = 0;
	dst = (unsigned char *)dest;
	if (dest > src)
	{
		while (size--)
			dst[size] = sc[size];
	}
	if (dest < src)
	{
		while (size--)
		{	
			dst[i] = sc[i];
			i++;
		}
	}
	return (dest);
}
