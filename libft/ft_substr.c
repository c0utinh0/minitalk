/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:39:09 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/13 07:53:37 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	slen;	

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	sub = ft_calloc(1, sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (start > ft_strlen(s))
		return (sub);
	while (i++ < start)
		s++;
	i = 0;
	while ((len-- > 0) && (*s != '\0'))
		sub[i++] = *s++;
	return (sub);
}
