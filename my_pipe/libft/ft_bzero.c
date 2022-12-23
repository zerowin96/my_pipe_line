/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:42:34 by yeham             #+#    #+#             */
/*   Updated: 2022/07/12 21:09:05 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t size)
{
	size_t			i;
	unsigned char	*dst;

	dst = (unsigned char *)dest;
	i = 0;
	while (i < size)
	{
		dst[i] = 0;
		i++;
	}
}
