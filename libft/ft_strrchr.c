/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:48:46 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/10 08:51:28 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*m_str;
	int		i;

	m_str = NULL;
	i = ft_strlen((char *)str) + 1;
	if (c == 0)
		return ((char *)&str[--i]);
	while (i--)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	}
	return (m_str);
}
