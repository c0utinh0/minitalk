/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:09:45 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/06 11:15:29 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_print_u(unsigned int u)
{
	int		len;
	char	c;

	len = ft_intlen(u);
	if (u >= 10)
	{
		ft_print_int(u / 10);
		u = u % 10;
	}
	c = u + 48;
	write(1, &c, 1);
	return (len);
}
