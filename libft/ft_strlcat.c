/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:17:24 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/02 13:31:43 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*temp_d;
	const char	*temp_s;
	size_t		i;
	size_t		len_dst;

	temp_d = dst;
	temp_s = src;
	i = dstsize;
	while (i-- != 0 && *temp_d != '\0')
		temp_d++;
	len_dst = temp_d - dst;
	i = dstsize - len_dst;
	if (i == 0)
		return (len_dst + ft_strlen((char *)temp_s));
	while (*temp_s != '\0')
	{
		if (i != 1)
		{
			*temp_d++ = *temp_s;
			i--;
		}
		temp_s++;
	}
	*temp_d = '\0';
	return (len_dst + (temp_s - src));
}
