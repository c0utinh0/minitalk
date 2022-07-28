/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:17:03 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/02 11:36:20 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	while (n--)
	{
		if (((unsigned char)*str1 - (unsigned char)*str2) != 0)
			return ((int)(unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
	}
	return (0);
}
