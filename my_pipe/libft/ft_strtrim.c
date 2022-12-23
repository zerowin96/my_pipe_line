/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:14:27 by yeham             #+#    #+#             */
/*   Updated: 2022/07/12 22:27:51 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		e;
	int		i;
	char	*sc;

	if (s1 == 0)
		return (0);
	i = 0;
	s = 0;
	e = ft_strlen(s1);
	while (s1[s] && check(s1[s], set))
		s++;
	while (e > s && check(s1[e - 1], set))
		e--;
	sc = (char *)malloc(sizeof(char) * (e - s + 1));
	if (sc == NULL)
		return (0);
	while (e > s)
	{
		sc[i] = s1[s];
		i++;
		s++;
	}
	sc[i] = '\0';
	return (sc);
}
