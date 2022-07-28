/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:58:33 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/13 07:34:34 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		size = 1;
		count = size;
	}
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}
