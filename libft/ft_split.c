/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:53 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/08 12:18:40 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_core(char const *s, char c, char **matrix)
{
	unsigned int	m;
	char			*tmp;
	char			*sub;

	m = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			tmp = ft_strchr(s, c);
			if (tmp == NULL)
			{
				sub = (char *)s;
				tmp = (char *)s;
				tmp = tmp + ft_strlen(s);
			}
			sub = ft_substr(s, 0, tmp - s);
			s = tmp;
			matrix[m++] = sub;
		}
	}
	matrix[m] = NULL;
	return (matrix);
}

static size_t	ft_count_m(char const *s, char c)
{
	size_t		count;
	char		*tmp;

	tmp = (char *)s;
	count = 0;
	while (*tmp != 0)
	{
		while (*tmp == c && *tmp != 0)
			++tmp;
		while (*tmp != c && *tmp != 0)
			++tmp;
		if (*(tmp - 1) != c)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	num;

	if (!s)
		return (NULL);
	num = ft_count_m(s, c);
	matrix = (char **)malloc(sizeof(char *) * (num + 1));
	if (!matrix)
		return (NULL);
	if (s[0] == 0)
	{
		matrix[0] = NULL;
		return (matrix);
	}	
	matrix = ft_core(s, c, matrix);
	return (matrix);
}
