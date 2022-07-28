/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:50:38 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/02 17:23:55 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		n;

	n = ft_strlen((char *)s) + 1;
	dst = malloc(sizeof(char) * (n));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s, n);
	return (dst);
}
