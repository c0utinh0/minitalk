/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:53:49 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/06 08:06:27 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*m_dst;
	char	*m_src;
	char	*temp_src;
	char	*temp_dst;

	m_dst = dst;
	m_src = (char *)src;
	temp_src = NULL;
	temp_dst = NULL;
	if (dst == NULL && src == NULL && len)
		return (dst);
	if (m_dst < m_src)
	{
		while (len--)
			*m_dst++ = *m_src++;
	}
	else
	{
		temp_src = m_src + (len - 1);
		temp_dst = m_dst + (len - 1);
		while (len--)
			*temp_dst-- = *temp_src--;
	}
	return (dst);
}
