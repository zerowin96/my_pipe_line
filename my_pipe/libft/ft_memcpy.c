/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:51:18 by yeham             #+#    #+#             */
/*   Updated: 2022/07/12 22:07:08 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char		*dst;
	const char	*sc;

	dst = (char *)dest;
	sc = (const char *)src;
	if (dst == sc)
		return (dest);
	while (size--)
	{
		*dst = *sc;
		dst++;
		sc++;
	}
	return (dest);
}
