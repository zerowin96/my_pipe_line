/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:16:08 by yeham             #+#    #+#             */
/*   Updated: 2022/11/30 18:48:53 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *dest, int value, size_t size)
{
	unsigned char	*dst;

	dst = (unsigned char *)dest;
	while (size--)
	{
		*dst = (unsigned char)value;
		dst++;
	}
	return (dest);
}
