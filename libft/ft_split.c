/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:05 by yeham             #+#    #+#             */
/*   Updated: 2022/07/24 19:18:33 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordlen(char const *s, char c)
{
	int	size;
	int	j;

	j = 0;
	size = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && (*s != c))
		{
			while (*s && (*s != c))
				s++;
			j++;
		}
	}
	return (j);
}

char	cpy(char **sp, char const *start, char const *s, int j)
{
	int	len;
	int	k;

	k = 0;
	len = s - start;
	sp[j] = (char *)malloc(sizeof(char) * (len + 1));
	if (sp[j] == NULL)
	{
		while (--j)
			free(sp[j]);
		free(sp);
		return (0);
	}
	while (k < len)
	{
		sp[j][k] = start[k];
		k++;
	}
	sp[j][k] = 0;
	return (1);
}

char	**nom(char **sp, char const *s, char c)
{
	char const	*start;
	int			j;

	j = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		start = s;
		if (*s && (*s != c))
		{
			while (*s && (*s != c))
				s++;
			if (cpy(sp, start, s, j) == 0)
				return (0);
			j++;
		}
	}
	sp[j] = 0;
	return (sp);
}

char	**ft_split(char const *s, char c)
{
	char		**sp;

	if (s == 0)
		return (0);
	sp = (char **)malloc(sizeof(char *) * (wordlen(s, c) + 1));
	if (sp == NULL)
		return (0);
	return (nom(sp, s, c));
}
