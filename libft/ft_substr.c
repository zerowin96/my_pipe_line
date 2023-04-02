/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:54:42 by yeham             #+#    #+#             */
/*   Updated: 2022/07/12 22:10:52 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*sc;

	if (s == 0)
		return (0);
	size = ft_strlen(s);
	i = 0;
	if (size < start)
		len = 0;
	else if (len > size - start)
		len = size - start;
	sc = (char *)malloc(sizeof(char) * (len + 1));
	if (sc == NULL)
		return (0);
	while (len--)
	{
		sc[i] = s[start];
		start++;
		i++;
	}
	sc[i] = '\0';
	return (sc);
}
