/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:06:39 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/02 11:25:24 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*m_dst;

	m_dst = (char *)dst;
	if (dst == NULL && src == NULL && n)
		return (dst);
	while (n-- > 0)
		*m_dst++ = *(char *)src++;
	return (dst);
}
