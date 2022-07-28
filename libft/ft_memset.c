/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:42:23 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/05/17 09:04:25 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t num)
{
	size_t			i;
	unsigned char	*str;

	str = b;
	i = 0;
	while (i < num)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (str);
}
