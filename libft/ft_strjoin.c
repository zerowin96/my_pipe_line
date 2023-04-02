/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:03:09 by yeham             #+#    #+#             */
/*   Updated: 2022/07/12 22:10:22 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*sc;

	if (s1 == 0 || s2 == 0)
		return (0);
	j = 0;
	i = 0;
	sc = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (sc == NULL)
		return (0);
	while (s1[i])
	{
		sc[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		sc[i + j] = s2[j];
		j++;
	}
	return (sc);
}
