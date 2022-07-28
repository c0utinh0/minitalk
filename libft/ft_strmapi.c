/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:27:49 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/10 15:27:55 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;	
	char			*str;

	i = 0;
	if (!s)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
