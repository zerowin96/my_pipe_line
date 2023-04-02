/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:32:21 by yeham             #+#    #+#             */
/*   Updated: 2022/07/15 15:08:37 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (size != 0 && SIZE_MAX / size < count)
		return (0);
	temp = malloc(size * count);
	if (temp == NULL)
		return (0);
	ft_memset(temp, 0, size * count);
	return (temp);
}
